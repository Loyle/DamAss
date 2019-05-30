//
// Created by marco on 24/05/2019.
//

#include <SDL2/SDL.h>
#include "draw.h"
#include "../board/cellStructure.h"

void drawSquareHelp(SDL_Renderer* renderer,int x, int y, Cell **board){

    // We don't want to draw on a Dame
    if(board[x][y].hasDame == 0 && board[x][y].isEnable == 1) {
        SDL_Color green = {0,183,0,255};
        SDL_SetRenderDrawColor(renderer, green.r,green.g,green.b,green.a);
        SDL_Rect rect = {x*80+80+35,y*80+80+35,10,10};
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }
    if(board[x][y].isConflict == 1 && board[x][y].hasDame == 0 && board[x][y].isEnable == 1){
        SDL_Color red = {255,0,0,255};
        SDL_SetRenderDrawColor(renderer, red.r,red.g,red.b,red.a);
        SDL_Rect rect = {x*80+80+35,y*80+80+35,10,10};
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }
}