//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>

/***DRAW DAME SPRITE***/
void drawSprite(SDL_Window* pWindow,SDL_Renderer* renderer,int x,int y,int color)
{
    SDL_Surface* spriteDameBeige = SDL_LoadBMP("./data/beige_semi_small.bmp"); /* color = 0*/
    SDL_Surface* spriteDameBrown = SDL_LoadBMP("./data/brun_semi_small.bmp"); /* color = 1*/

    int X,Y ;
    SDL_GetWindowSize(pWindow,&X,&Y);

    if(color == 0 )
    {
        if ( spriteDameBeige )
        {
            SDL_Texture* sDameBeige = SDL_CreateTextureFromSurface(renderer,spriteDameBeige);
            printf("DRAW\n");
            SDL_Rect dest = {x, y, Y/10, Y/10};
            SDL_RenderCopy(renderer,sDameBeige,NULL,&dest);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(sDameBeige);
        }
        else
        {
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }
    }
    else if (color == 1 )
    {
        if ( spriteDameBrown )
        {
            SDL_Texture* sDameBrown = SDL_CreateTextureFromSurface(renderer,spriteDameBrown);
            printf("DRAW\n");
            SDL_Rect dest = {x, y, Y/10, Y/10};
            SDL_RenderCopy(renderer,sDameBrown,NULL,&dest);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(sDameBrown);
        }
        else
        {
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }
    }
    SDL_FreeSurface(spriteDameBeige);
    SDL_FreeSurface(spriteDameBrown);
}