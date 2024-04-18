//
// Created by aleks on 14.07.2023.
//

#ifndef UNTITLED_PLACEMENT_H
#define UNTITLED_PLACEMENT_H
#include "structures.h"
void setPenguinLocation(struct point* penguinLocation, uint8_t xMax,uint8_t yMax,uint8_t* pBoard);
    //asks the user for coordinates of the placement,
    //runs repeatedly until the coordinates can satisfy checkPenguinLocation conditions

void placement(uint8_t* Board, uint8_t columns, uint8_t rows, struct point penguinLocation[6]);
    //sets the penguin array to 0, then sets penguin locations for every penguin
void resetLocation(struct point ptArr[6]);
    //used on creation of the array to set its values to 0

bool checkPenguinLocation(struct point penguinLocation,uint8_t xMax,uint8_t* pBoard, bool placement);
    //checks if a penguin can be placed on a tile
    //penguin can't stand on water (0), or another penguin
#endif //UNTITLED_PLACEMENT_H

