//
// Created by marco on 24/05/2019.
//


#include "cellStructure.h"
#include "board.h"

void getPositionOnBoard(int *x , int *y, Board* board){

    *x = (*x-board->xDecal)/(board->cells[0][0].size);
    *y = (*y-board->yDecal)/(board->cells[0][0].size);

    if(*x >= board->size) {
        *x = board->size-1;
    }
    if(*y >= board->size) {
        *y = board->size-1;
    }
}