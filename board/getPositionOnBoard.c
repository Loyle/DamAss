//
// Created by marco on 24/05/2019.
//


#include "cellStructure.h"

void getPositionOnBoard(int *x , int *y, Cell** board){

    *x = (*x-board[0][0].decal)/(board[0][0].size);
    *y = (*y-board[0][0].decal)/(board[0][0].size);
    if(*x >= 8) {
        *x = 7;
    }
    if(*y >= 8) {
        *y = 7;
    }

}