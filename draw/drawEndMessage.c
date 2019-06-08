//
// Created by marco on 08/06/2019.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "../draw/draw.h"
#include "../board/board.h"
#include "../event/eventDetector.h"


int drawEndMessage(SDL_Window *pWindow,SDL_Renderer *renderer, Board* board,int* level, int *nbDame){
    SDL_Surface *resultSurface;

        /** Si toutes les dames  sont posées **/
        int good = 1;
        for (int x = 0; x < board->size ; x++) {
            for (int y = 0; y <board->size ; y++) {
                if(board->cells[x][y].hasDame) {
                    checkDameConflict(board,x,y);
                    if(board->cells[x][y].isConflict) {
                        good = 0;
                    }
                }
            }
        }

        if (good == 1){
            resultSurface = SDL_LoadBMP("./data/YOUWIN.bmp");
        }else{
            resultSurface = SDL_LoadBMP("./data/LOST.bmp");
        }


        if (resultSurface)
        {
            Uint32 colorkey = SDL_MapRGB(resultSurface->format,0,255,0);
            SDL_SetColorKey( resultSurface, SDL_RLEACCEL || resultSurface, colorkey );

            SDL_Texture *resultTexture = SDL_CreateTextureFromSurface(renderer, resultSurface);
            SDL_Rect dest = {0,0,1000,800};
            SDL_RenderCopy(renderer, resultTexture, NULL, &dest);

            SDL_DestroyTexture(resultTexture);
            SDL_FreeSurface(resultSurface);
        }else
        {
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }


    SDL_RenderPresent(renderer);
    return eventEndDetector(pWindow,renderer,board,level,nbDame);
}
