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

#endif //DAMASS_DRAW_H
