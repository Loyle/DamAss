//
// Created by marco on 24/05/2019.
//


#include "cellStructure.h"

void getPositionOnBoard(int *x , int *y, Cell** board){

    *x = *x%(board[0][0].size-1);
    *y = *y%(board[0][0].size-1);

}