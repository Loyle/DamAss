//
// Created by marco on 06/06/2019.
//
#include <SDL2/SDL.h>
#include "draw.h"
#include <stdio.h>

void clearSelectedLevel(SDL_Renderer* renderer,int level){
    SDL_Color black = {0,0,0,255};


    if( level == 0){
        SDL_Rect pos = {60,320,300,50};
        SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b,
                               black.a);
        SDL_RenderDrawRect(renderer,&pos);
    }else if (level == 1){
        SDL_Rect pos = {60,393,200,50};
        SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b,
                               black.a);
        SDL_RenderDrawRect(renderer,&pos);
    }else if (level == 2){
        SDL_Rect pos = {60,465,425,50};
        SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b,
                               black.a);
        SDL_RenderDrawRect(renderer,&pos);
    }else {
        SDL_Rect pos = {60,542,215,50};
        SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b,
                               black.a);
        SDL_RenderDrawRect(renderer,&pos);
    }
}
