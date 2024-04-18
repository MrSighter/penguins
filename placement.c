//
// Created by aleks on 14.07.2023.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "placement.h"
#include "utility_functions.h"
#include "colors.h"
void placement(uint8_t* Board, uint8_t columns, uint8_t rows, struct point penguinLocation[6]){
    resetLocation(penguinLocation);
    for (uint8_t i = 0; i < 6; ++i) {
        printBoard(Board, columns, rows);
        printf("%sPlayer %d%s, please place your penguin.\n", getPlayerColor(i & 1), i & 1, RESET);
        setPenguinLocation((penguinLocation+i/2+i%2*3), columns, rows, Board);
        *(Board+penguinLocation[i/2+i%2*3].x+penguinLocation[i/2+i%2*3].y*columns)=(short)(65+i/2+i%2*3);
    }
    printf("All penguins placed!\n");
}
void setPenguinLocation(struct point* penguinLocation, uint8_t xMax, uint8_t yMax, uint8_t* pBoard) {
    char buf[10];
    do {
        do {
            printf("Please enter the %sX%s coordinate: ", BOLDWHITE, RESET);
            fgets(buf, 10, stdin);
            fflush(stdin);
            penguinLocation->x = (uint8_t)strtol(buf, NULL, 10);
            penguinLocation->x--;
            memset(buf, 0, sizeof(buf));
            if (penguinLocation->x < 1 || penguinLocation->x > -1 + yMax) {
                printf("%sWrong X coordinate!%s\n", BOLDRED, RESET);
            }
        } while (penguinLocation->x < 1 || penguinLocation->x > -1 + yMax);

        do {
            printf("Please enter the %sY%s coordinate: ", BOLDWHITE, RESET);
            fgets(buf, 10, stdin);
            fflush(stdin);
            penguinLocation->y = (uint8_t)strtol(buf, NULL, 10);
            penguinLocation->y--;
            memset(buf, 0, sizeof(buf));

            if (penguinLocation->y < 1 || penguinLocation->y > -1 + yMax) {
                printf("%sWrong Y coordinate!%s\n", BOLDRED, RESET);
            }
        } while (penguinLocation->y < 1 || penguinLocation->y > -1 + yMax);
        if(!checkPenguinLocation(*penguinLocation, xMax, pBoard, true)) printf("%sChosen tile has to be a 1!%s\n",BOLDRED,RESET);
    } while (!checkPenguinLocation(*penguinLocation, xMax, pBoard, true));
}

bool checkPenguinLocation(struct point penguinLocation,uint8_t xMax, uint8_t* pBoard, bool placement){
    uint8_t tempVal = getValue(pBoard,penguinLocation,xMax);
    return tempVal < 1 || tempVal > 3 || (placement && tempVal != 1) ? false : true;
}
void resetLocation(struct point ptArr[6]){
    for (int i = 0; i < 6; ++i) {
        ptArr[i].x=0;
        ptArr[i].y=0;
    }
}