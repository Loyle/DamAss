//
// Created by Antoine on 21/05/2019.
//

#ifndef LP25_BOARD_H
#define LP25_BOARD_H

#include "cellStructure.h"

void checkDameConflict();
Cell **initBoard(int size, int cellSize, int decal);
void getPositionOnBoard(int *x , int *y, Cell** board);
#endif //LP25_BOARD_H
