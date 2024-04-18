//
// Created by aleks on 14.07.2023.
//

#ifndef UNTITLED_STRUCTURES_H
#define UNTITLED_STRUCTURES_H
#include <stdbool.h>
struct point{
    uint8_t x;
    uint8_t y;
    bool movable;
    //bool ???; need one more bool to use space left otherwise for padding
};
    //struct used for penguin location
    //X and Y are coordinates on the board
    //movable is assigned after every move
    //it determines if a penguin can move
#endif //UNTITLED_STRUCTURES_H
