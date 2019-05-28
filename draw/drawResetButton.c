//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "draw.h"

/*** DRAW RESET BUTTON ***/
void drawResetButton(SDL_Renderer* renderer){
    SDL_Surface* reset = SDL_LoadBMP("./data/RESET.bmp");

    if (reset)
    {
        Uint32 colorkey = SDL_MapRGB(reset->format,0,255,0);
        SDL_SetColorKey( reset, SDL_RLEACCEL || reset, colorkey );

        SDL_Texture* sReset = SDL_CreateTextureFromSurface(renderer,reset);
        SDL_Rect dest = {810,650,100,100};
        SDL_RenderCopy(renderer,sReset,NULL,&dest);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(sReset);
    }else
    {
        fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
    }

}
