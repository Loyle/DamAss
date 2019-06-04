//
// Created by marco on 24/05/2019.
//

#include <SDL2/SDL.h>
#include "draw.h"
#include "../board/cellStructure.h"

void drawSquareHelp(SDL_Renderer* renderer,int x, int y, Board *board){
    int sizeSmallSquare = 0.125*board->cells[0][0].size;

    // We don't want to draw on a Dame
    if(board->cells[x][y].hasDame == 0 && board->cells[x][y].isEnable == 1) {
    //if(board->cells[x][y].isEnable == 1) {
        SDL_Color green = {0,183,0,255};
        SDL_SetRenderDrawColor(renderer, green.r,green.g,green.b,green.a);
        SDL_Rect rect = {x*board->cells[0][0].size+board->xDecal+(board->cells[0][0].size-sizeSmallSquare)/2,
                         y*board->cells[0][0].size+board->yDecal+(board->cells[0][0].size-sizeSmallSquare)/2,
                         sizeSmallSquare,sizeSmallSquare};
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }
    if(board->cells[x][y].isConflict == 1 && board->cells[x][y].hasDame == 0 && board->cells[x][y].isEnable == 1){
        SDL_Color red = {255,0,0,255};
        SDL_SetRenderDrawColor(renderer, red.r,red.g,red.b,red.a);
        SDL_Rect rect = {x*board->cells[0][0].size+board->xDecal+(board->cells[0][0].size-sizeSmallSquare)/2,
                         y*board->cells[0][0].size+board->yDecal+(board->cells[0][0].size-sizeSmallSquare)/2,
                         sizeSmallSquare,sizeSmallSquare};
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }
}