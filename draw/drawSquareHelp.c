//
// Created by marco on 24/05/2019.
//

#include <SDL2/SDL.h>

void drawSquareHelp(SDL_Window* pWindow,SDL_Renderer* renderer,int x, int y ){

    SDL_Color grey = {255,0,0,255};
    SDL_SetRenderDrawColor(renderer, grey.r,grey.g,grey.b,grey.a );
    SDL_Rect rect = {x*80+80+30,y*80+80+30,20,20};
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);

}