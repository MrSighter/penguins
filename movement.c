
//
// Created by aleks on 17.07.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include "movement.h"
#include "colors.h"
#include "utility_functions.h"

void movement(uint8_t* pBoard, struct point penguinArr[6],uint8_t  xMax,uint8_t yMax){
    uint8_t scores[2] = {3,3};
    bool currPlayer = false;
    for (uint8_t i = 0; i < 6; ++i) {
        canMove(pBoard, xMax, (penguinArr+i));
    }
    while(playerMovement(penguinArr, false)||playerMovement(penguinArr, true)){
        if(playerMovement(penguinArr, currPlayer)) {
            printBoard(pBoard, xMax, yMax);
            move(pBoard, penguinArr, xMax, currPlayer, &scores[currPlayer]);
        }
        for (uint8_t i = 0; i < 6; ++i) {
            canMove(pBoard, xMax, (penguinArr+i));
        }
        currPlayer^=true;
    }
    printf("No player can make a move.\nGame has ended.\n");
    if(scores[0]==scores[1])printf("Both players have the same score. It's a draw!\n");
    else if(scores[0]>scores[1])printf("Player %s1%s won\n", getPlayerColor(0), RESET);
    else printf("Player %s2%s won\n", getPlayerColor(1), RESET);
    printf("Scores:\n%sPlayer 1%s - %d\n%sPlayer 2%s - %d\n", getPlayerColor(0), RESET, scores[0], getPlayerColor(1), RESET, scores[1]);

    getchar();
}
uint8_t getPenguin( bool currPlayer){
    char buf[10];
    uint8_t penguin;
    bool check;
    do {
        printf("%sPlayer %d%s, make a move.\n", getPlayerColor(currPlayer),1+currPlayer,RESET);
        printf("Which penguin would you like to move?\n%sTip: Type in the letter of a penguin%s\n", "\033[2m", RESET);
        fgets(buf, 10, stdin);
        fflush(stdin);
        penguin = (uint8_t)((int)(buf[0]) - 65);
        check = checkPenguin(penguin, currPlayer);
        if(!check) printf("%sWrong penguin!%s\n", BOLDRED, RESET);
    } while(!check);
    return penguin;
}
bool checkPenguin(uint8_t penguin, bool currPlayer){
    if(!currPlayer){
        return penguin < 3&& penguin >= 0 ? true : false;
    }
    return penguin >= 3 && penguin < 6 ? true : false;
}
void getDir(uint8_t* pBoard, struct point* location, uint8_t* dir, uint8_t xMax){
    char buf[10];
    bool check;
    do {
        printf("Please enter the direction would you like to move your penguin\n%s1 - Left\n2 - Up\n3 - Right\n4 - Down\n\n%s",GRAY,RESET);
        fgets(buf, 10, stdin);
        fflush(stdin);
        *dir = (uint8_t)strtol(buf, NULL, 10);
        check = checkDir(pBoard, location, *dir, xMax);
        if(!check) printf("%sWrong direction!%s\n", BOLDRED,RESET);
    }while(!check);
    updateLocation(location,*dir);
}
bool checkDir(uint8_t* pBoard, struct point* location, uint8_t dir, uint8_t xMax){
    uint8_t* address= (pBoard+location->x+location->y*xMax);
    switch (dir) {
        case 1:
            if(*(address-1)<1||*(address-1)>3) return false;
            return true;
        case 2:
            if(*(address-xMax)<1||*(address-xMax)>3) return false;
            return true;
        case 3:
            if(*(address+1)<1||*(address+1)>3) return false;
            return true;
        case 4:
            if(*(address+xMax)<1||*(address+xMax)>3) return false;
            return true;
        default:
            return false;
    }
}
void updateLocation(struct point* location, uint8_t dir){
    switch (dir) {
        case 1:
            location->x--;
            break;
        case 2:
            location->y--;
            break;
        case 3:
            location->x++;
            break;
        case 4:
            location->y++;
            break;
        default:
            assert("Unexpected location. Please restart the game!\n");
    }
}
void move(uint8_t* pBoard, struct point penguinArr[6], uint8_t xMax, bool currPlayer,uint8_t* score){
    bool retry=false;
    uint8_t penguin, direction;
    struct point tempLocation;
    do {
        if(retry) printf("%sThis penguin cannot move!\n%s", BOLDRED, RESET);
        penguin = getPenguin(currPlayer);
        retry = true;
    } while(!penguinArr[penguin].movable);
    tempLocation.x=penguinArr[penguin].x;
    tempLocation.y=penguinArr[penguin].y;
    getDir(pBoard, &tempLocation, &direction, xMax);
    *score+= getValue(pBoard, tempLocation,xMax);
    *(pBoard+penguinArr[penguin].x+penguinArr[penguin].y*xMax)=0;
    *(pBoard+tempLocation.x+tempLocation.y*xMax) = (uint8_t)(penguin+65);
    penguinArr[penguin].x=tempLocation.x;
    penguinArr[penguin].y=tempLocation.y;
    canMove(pBoard,xMax,&penguinArr[penguin]);
}
void canMove(uint8_t* pBoard, uint8_t xMax, struct point* location){
    for (uint8_t i = 1; i < 5; ++i) {
        if (checkDir(pBoard, location, i, xMax)) {
            location->movable = true;
            return;
        }
    }
    location->movable=false;
}
bool playerMovement(struct point* locations, bool currPlayer){
    for (uint8_t i = 0; i < 3; ++i) {
        if((locations+i+3*currPlayer)->movable) return true;
    }
    return false;
}
