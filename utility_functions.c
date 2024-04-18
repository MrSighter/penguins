//
// Created by aleks on 19.07.2023.
//
#include <stdio.h>
#include <stdint.h>
#include "utility_functions.h"
#include "colors.h"

void printBoard(const uint8_t* Board, uint8_t columns, uint8_t rows){
    numberPrint(columns);

    columnDash(columns,"X");
    for (uint8_t i = 0; i < rows; ++i) {
        if(i<9)printf(" %s%d%s ", GRAY,1+i, RESET);
        else printf(" %s%d%s", GRAY,1+i, RESET);
        for (uint8_t j = 0; j < columns; ++j) {
            if(*(Board+j+i*columns)==0)
                printf(" |%s %d%s",BOLDBLUE, *(Board+j+i*columns),RESET);
            else
                switch (*(Board + j + i * columns)) {
                    case 1:
                    case 2:
                    case 3:
                        printf(" | %d", *(Board + j + i * columns));
                        break;
                    case 65:
                    case 66:
                    case 67:
                        printf(" |%s %c%s", RED, *(Board + j + i * columns), RESET);
                        break;
                    case 68:
                    case 69:
                    case 70:
                        printf(" |%s %c%s", GREEN, *(Board + j + i * columns), RESET);
                        break;
                }
        }
        printf(" |\n");
        columnDash(columns," ");
    }
}
void columnDash(uint8_t columns, char* message){
    printf(" %s%s%s  ",GRAY, message, RESET);
    for (uint8_t i = 0; i < columns; ++i) {
        printf(" ---");
    }
    printf("\n");
}
void numberPrint(uint8_t columns){
    printf("%s   Y",GRAY);
    for (int i = 1; i < 1+columns; ++i) {
        printf(i < 10 ? "  %d " : "  %d",i);
    }
    printf("%s\n", RESET);
}
uint8_t getValue(const uint8_t* pBoard, struct point pt, uint8_t xMax){
    return *(pBoard+pt.x+pt.y*xMax);
}
char* getPlayerColor(bool player){
    return player ?  GREEN : RED;
}