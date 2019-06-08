//
// Created by Antoine on 21/05/2019.
//

#ifndef LP25_BOARD_H
#define LP25_BOARD_H

#include "cellStructure.h"
#include <SDL2/SDL.h>

typedef struct Board Board;
struct Board {
    Cell **cells;
    int size;
    int nbDame;
    int xDecal;
    int yDecal;
};

Board *initBoard(int size, int decal);
void getPositionOnBoard(int *x , int *y, Board* board);
void checkDameConflict(Board* board, int x , int y);
void setConflictLine(Board* board ,int xCursor, int yCursor, int xEnd , int yEnd);
void setCellSprite(SDL_Renderer* renderer,int x,int y,Board* board,int isDame);
void setPreventSquareHelp(Board* board);
void resolver(SDL_Renderer* renderer,Board *board);
void resetConflicts(Board *board);

#endif //LP25_BOARD_H
