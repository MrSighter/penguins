
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "input.h"
#include "generation.h"
#include "structures.h"
#include "placement.h"
#include "movement.h"

int main() {
    struct point penguinLocation[6];
    uint8_t rows, columns;
    inputInfo();
    getColumns(&columns);
    getRows(&rows);
    uint8_t *board= calloc(columns*rows, sizeof(uint8_t));
    generate(columns, rows, board);
    placement(board,columns,rows, penguinLocation);
    movement(board,penguinLocation,columns, rows);
}
