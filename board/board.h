//
// Created by Antoine on 21/05/2019.
//

#ifndef LP25_BOARD_H
#define LP25_BOARD_H

#include "cellStructure.h"

typedef struct Board Board;
struct Board {
    Cell **cells;
    int size;
    int xDecal;
    int yDecal;
};

Cell **initBoard(int size, int cellSize, int decal);
void getPositionOnBoard(int *x , int *y, Cell** board);
void checkDameConflict(Cell** board, int x , int y);
void setConflictLine(Cell** board ,int xCursor, int yCursor, int xEnd , int yEnd);

#endif //LP25_BOARD_H
