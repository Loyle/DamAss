//
// Created by marco on 05/06/2019.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "draw.h"

void setTextNbDame(SDL_Window* pWindow,SDL_Renderer* renderer,int* level, int* nbDame){

    SDL_Rect pos = {772,465,50,75};
    SDL_Color white = {255,255,255,255};
    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b,
                           white.a);
    SDL_RenderFillRect(renderer, &pos);


    TTF_Init();
    TTF_Font *xlFont = TTF_OpenFont("./data/font/RobotoCondensedLight.ttf", 200);

    SDL_Color blackPen = {0, 0, 0};
    char string[5] = "";
    sprintf(string,"%i",*nbDame);

    SDL_Surface *textSurface = TTF_RenderText_Solid(xlFont,string , blackPen);

    SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_RenderCopy(renderer, text, NULL, &pos);


    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(text);

    TTF_CloseFont(xlFont);
    TTF_Quit();

    SDL_RenderPresent(renderer);
}