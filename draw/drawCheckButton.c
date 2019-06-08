//
// Created by marco on 08/06/2019.
//

#include <SDL2/SDL.h>
#include <stdio.h>
#include "draw.h"

/*** DRAW CHECK BUTTON ***/
#include <SDL2/SDL.h>
#include <stdio.h>
#include "draw.h"

/*** DRAW RESET BUTTON ***/
void drawCheckButton(SDL_Renderer* renderer){
    SDL_Surface* check = SDL_LoadBMP("./data/CHECK.bmp");

    if (check)
    {
        Uint32 colorkey = SDL_MapRGB(check->format,0,255,0);
        SDL_SetColorKey( check, SDL_RLEACCEL || check, colorkey );

        SDL_Texture* sCheck = SDL_CreateTextureFromSurface(renderer,check);
        SDL_Rect dest = {810,595,100,100};
        SDL_RenderCopy(renderer,sCheck,NULL,&dest);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(sCheck);
    }else
    {
        fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
    }

}



