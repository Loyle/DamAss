//
// Created by marco on 21/05/2019.
//

#ifndef DAMASS_DRAW_H
#define DAMASS_DRAW_H

#include <SDL2/SDL.h>
#include "../board/board.h"
#include "../board/cellStructure.h"

void drawResetButton(SDL_Renderer*);
void drawMenuButton(SDL_Renderer* renderer);
void drawChessboard(SDL_Renderer*,Board *board);
void drawHelp(SDL_Renderer*,int x, int y, Board *board);
void drawSquareHelp(SDL_Renderer*,int x, int y, Board *board);
void initGameWindows(SDL_Renderer *, Board *board);
void drawScoreBoard(SDL_Renderer *renderer, int rest);

int initHome(SDL_Window *pWindow ,SDL_Renderer *renderer,int* level, int* nbDame);

void setTextNbDame(SDL_Renderer* renderer, int* nbDame);

void clearSelectedLevel(SDL_Renderer* renderer,int level);


#endif //DAMASS_DRAW_H
