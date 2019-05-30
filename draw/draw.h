//
// Created by marco on 21/05/2019.
//

#ifndef DAMASS_DRAW_H
#define DAMASS_DRAW_H

#include <SDL2/SDL.h>
#include "../board/cellStructure.h"

void drawSprite(SDL_Renderer*,int x,int y,Cell** board, int isDame);
void drawResetButton(SDL_Renderer*);
void drawChessboard(SDL_Renderer*,Cell **board);
void drawHelp(SDL_Renderer*,int x, int y, Cell **board);
void drawSquareHelp(SDL_Renderer*,int x, int y, Cell **board);
void initGameWindows(SDL_Renderer *, Cell **board);
void drawScoreBoard(SDL_Renderer *renderer, int rest);
void setPreventSquareHelp(Cell** board,int x , int y);

#endif //DAMASS_DRAW_H
