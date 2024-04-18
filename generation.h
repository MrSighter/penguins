//
// Created by aleks on 13.07.2023.
//

#ifndef UNTITLED_GENERATION_H
#define UNTITLED_GENERATION_H
#include <stdbool.h>
uint8_t* generate(uint8_t columns, uint8_t rows, uint8_t* board);
    //returns a random generated board
    //edges of the board will always be 0
    //uses RandomTile for the rest of the tiles

uint8_t randomTile();
    //return a number from 0 to 3 randomly
    //chances for 0|1|2|3 are 2:9:6:3 respectively

bool checkBorder(uint8_t columns, uint8_t rows, int i);
    //checks if i is on the border of the board
    //used in generate

bool checkBoard(const uint8_t* pBoard,uint8_t rows, uint8_t columns );
    //checks if the Board is playable I.E. if there are enough 1's on the board
#endif //UNTITLED_GENERATION_H
