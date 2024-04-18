//
// Created by aleks on 14.07.2023.
//

#ifndef UNTITLED_INPUT_H
#define UNTITLED_INPUT_H
#include <stdbool.h>
#include <stdint.h>

void inputInfo();
    //prints out the information about input conditions at the start of the game

void getColumns(uint8_t* num);
    //sets the number of columns
    //will set num to 6 if the input number is less than 5 or more than 20

void getRows(uint8_t *num);
    //sets the number of columns
    //will set num to 6 if the input number is less than 5 or more than 20
#endif //UNTITLED_INPUT_H
