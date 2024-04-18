
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "generation.h"
uint8_t *generate(uint8_t columns, uint8_t rows, uint8_t *board) {
    time_t t;
    srand((unsigned int) time(&t));

    for (int i = 0; i < columns * rows; ++i)
        *(board + i) = checkBorder(columns, rows, i) ? 0 : randomTile();

    return !checkBoard(board, rows, columns) ? generate(columns, rows, board) : board;
}
uint8_t randomTile(){
    uint8_t randomNumber  = (uint8_t)(rand() % 100 + 1);
    return randomNumber < 10 ? 0 : randomNumber < 55 ? 1 : randomNumber < 85 ? 2 : 3;
}
bool checkBorder(uint8_t columns, uint8_t rows,  int i){
    return i < columns || i > (rows * columns - columns) || i % columns == 0 || i % columns == -1 + columns ? true : false;
}

bool checkBoard(const uint8_t* pBoard,const uint8_t rows,const  uint8_t columns ){
    uint8_t counter=0;
    for (int i = 0; i < rows*columns; ++i) {
        if(*(pBoard+i)==1){
            counter++;
            if (counter >= 6) return true;
        }
    }
    return false;
}