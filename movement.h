//
// Created by aleks on 17.07.2023.
//

#ifndef UNTITLED_MOVEMENT_H
#define UNTITLED_MOVEMENT_H
#include <stdbool.h>
#include "structures.h"
#include "generation.h"
void movement(uint8_t* pBoard, struct point penguinArr[6], uint8_t xMax,uint8_t yMax);


uint8_t getPenguin(bool currPlayer);
//Asks player to choose which penguin they would like to move

bool checkPenguin(uint8_t penguin, bool currPlayer);
//checks if the chosen penguin belongs to the current player

void getDir(uint8_t* pBoard, struct point* location, uint8_t* dir, uint8_t xMax);
//Asks player to type in direction in which the chosen penguin should move
//1-Left
//2-Down
//3 - Right
//4 - Up

bool checkDir(uint8_t* pBoard,struct point* location, uint8_t dir, uint8_t xMax);
//Checks if penguin can move in chosen direction

void updateLocation(struct point* location, uint8_t dir);
//updates X and Y of the location passed into the function

void move(uint8_t* pBoard, struct point penguinArr[6], uint8_t xMax, bool currPlayer, uint8_t* score);
//Invokes penguin and direction functions
//Updates penguins location struct and board after move
//Assigns score

void canMove(uint8_t* pBoard, uint8_t xMax, struct point* location);
//Checks if a penguin can move in any direction
//Assigns movable variable in penguins location struct

bool playerMovement( struct point* locations, bool currPlayer);
//Checks if current Player can move
//Skips player turn if not


#endif //UNTITLED_MOVEMENT_H
