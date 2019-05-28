#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "draw.h"
#include "../board/cellStructure.h"

//
// Created by Antoine on 28/05/2019.
//

void initGameWindows(SDL_Renderer* renderer, Cell **board) {
    SDL_SetRenderDrawColor(renderer, 208, 208, 208, 255);
    SDL_RenderClear(renderer);

    drawChessboard(renderer, board);
    drawResetButton(renderer);
    drawScoreBoard(renderer,8);
}