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

Board *initBoard(int size, int cellSize, int decal);
void getPositionOnBoard(int *x , int *y, Board* board);
void checkDameConflict(Board* board, int x , int y);
void setConflictLine(Board* board ,int xCursor, int yCursor, int xEnd , int yEnd);
void setCellSprite(int x,int y,Board* board);
void setPreventSquareHelp(Board* board);
void resolver(Board *board);

#endif //LP25_BOARD_H
