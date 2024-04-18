//
// Created by aleks on 14.07.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "colors.h"

void inputInfo(){
    printf("Now you will set the parameters of the board.\n");
    printf("%sIf you make any mistake in typing (Ex. put a letter instead of the number),\n",GRAY);
    printf("the game will take a default value instead!\n");
    printf("The default value of rows and columns is 10.%s\n",RESET);
}
void getColumns(uint8_t * num){
    char buf[100];

    printf("Please input the number of cells in a column.\n");
    printf("%sPlease note, that the minimum and maximum number of cells are 6 and 20 respectively!%s\n",GRAY, RESET);

    fgets(buf,100, stdin);
    *num=(uint8_t)strtol(buf,NULL,10);
    if(*num<=5||*num>20) {
        printf("%sError in assigning columns. Setting the default value (10).%s\n\n",BOLDRED, RESET);
        fflush(stdin);
        *num=10;
    }
}
void getRows(uint8_t* num){
    char buf[100];
    printf("Please input the number of columns.\n");
    printf("%sPlease note, that the minimum and maximum number of rows are 6 and 20 respectively!%s\n",GRAY, RESET);
    fgets(buf,100, stdin);
    *num=(uint8_t)strtol(buf,NULL,10);
    if(*num<=5||*num>20) {
        printf("%sError in assigning rows. Setting the default value (10).%s\n\n",BOLDRED, RESET);
        fflush(stdin);
        *num=10;
    }

}
