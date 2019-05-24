//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../board/cellStructure.h"

/***DRAW DAME SPRITE***/
void drawSprite(SDL_Window* pWindow,SDL_Renderer* renderer,int x,int y,Cell **board)
{
    SDL_Surface* spriteDameBeige = SDL_LoadBMP("./data/beige_semi_small.bmp"); /* color = 0*/
    SDL_Surface* spriteDameBrown = SDL_LoadBMP("./data/brun_semi_small.bmp"); /* color = 1*/

    /*int X,Y ;
    SDL_GetWindowSize(pWindow,&X,&Y);*/


        if ( spriteDameBeige && spriteDameBrown )
        {
            SDL_Texture* sDameBeige = SDL_CreateTextureFromSurface(renderer,spriteDameBeige);
            SDL_Texture* sDameBrown = SDL_CreateTextureFromSurface(renderer,spriteDameBrown);

            SDL_Rect dest = {board[x][y].pixelX, board[x][y].pixelY, board[x][y].size, board[x][y].size};
            if((x+y)%2){
                SDL_RenderCopy(renderer,sDameBeige,NULL,&dest);
            }
            else{
                SDL_RenderCopy(renderer,sDameBrown,NULL,&dest);
            }
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(sDameBeige);
        }
        else
        {
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }

    SDL_FreeSurface(spriteDameBeige);
    SDL_FreeSurface(spriteDameBrown);
}