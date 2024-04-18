//
// Created by aleks on 19.07.2023.
//

#ifndef UNTITLED_UTILITY_FUNCTIONS_H
#define UNTITLED_UTILITY_FUNCTIONS_H
#include "structures.h"

void printBoard(const uint8_t* Board, uint8_t columns, uint8_t rows);
    //prints board as a series of numbers with " | " between the numbers
    //prints 0 as blue, and players as their respective colors
    //uses escape sequences for coloring
void columnDash(uint8_t columns, char* message);
    //prints a horizontal dash line between tile
void numberPrint(uint8_t columns);
    //Prints number from 1 up to columns indicating columns of the board
uint8_t getValue(const uint8_t* pBoard, struct point pt, uint8_t xMax);
    //returns value of an address
char* getPlayerColor(bool Player);
    //return escape sequence (color) of a chosen player as a string
#endif //UNTITLED_UTILITY_FUNCTIONS_H
