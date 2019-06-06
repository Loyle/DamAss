//
// Created by marco on 06/06/2019.
//

#include <SDL2/SDL.h>
#include <stdio.h>
#include "draw.h"

/*** DRAW RESET BUTTON ***/
void drawMenuButton(SDL_Renderer* renderer){
    SDL_Surface* menu = SDL_LoadBMP("./data/MENU.bmp");

    if (menu)
    {
        Uint32 colorkey = SDL_MapRGB(menu->format,0,255,0);
        SDL_SetColorKey( menu, SDL_RLEACCEL || menu, colorkey );

        SDL_Texture* sMenu = SDL_CreateTextureFromSurface(renderer,menu);
        SDL_Rect dest = {810,540,100,100};
        SDL_RenderCopy(renderer,sMenu,NULL,&dest);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(sMenu);
    }else
    {
        fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
    }

}

