//
// Created by marco on 05/06/2019.
//

#include <SDL2/SDL.h>
#include "draw.h"
#include <stdio.h>
#include "../event/eventDetector.h"

int initHome(SDL_Window *pWindow ,SDL_Renderer *renderer,int* level,int *nbDame){

    SDL_Surface* home = SDL_LoadBMP("./data/HOME.bmp");

    if (home)
    {
        SDL_Texture* sHome = SDL_CreateTextureFromSurface(renderer,home);
        SDL_Rect dest = {0,0,1000,800};
        SDL_RenderCopy(renderer,sHome,NULL,&dest);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(sHome);
    }else
    {
        fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
    }

    return eventHomeDetector(pWindow,renderer,level,nbDame);

}