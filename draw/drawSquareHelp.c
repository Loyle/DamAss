//
// Created by marco on 24/05/2019.
//

#include <SDL2/SDL.h>
#include "draw.h"
#include "../board/cellStructure.h"

void drawSquareHelp(SDL_Window* pWindow,SDL_Renderer* renderer,int x, int y, Cell **board){

    // We don't want to draw on a Dame
    if(board[x][y].hasDame == 0) {
        SDL_Color grey = {255,0,0,255};
        SDL_SetRenderDrawColor(renderer, grey.r,grey.g,grey.b,grey.a);
        SDL_Rect rect = {x*80+80+35,y*80+80+35,10,10};
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }
}