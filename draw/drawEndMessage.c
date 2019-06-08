//
// Created by marco on 08/06/2019.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "../draw/draw.h"
#include "../board/board.h"



void drawEndMessage(SDL_Renderer *renderer, Board* board){
    SDL_Surface *resultSurface;

    if (board->nbDame == 0){
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

    }else{
        /** Sinon message erreur **/
        SDL_Rect pos = {750,300,200,25};
        SDL_Color white = {208,208,208,255};
        SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b,
                               white.a);
        SDL_RenderFillRect(renderer, &pos);

        TTF_Init();
        TTF_Font *xlFont = TTF_OpenFont("./data/font/RobotoCondensedLight.ttf", 200);

        SDL_Color redPen = {255, 0, 0};
        char string[35]="";
        sprintf(string,"Dame(s) manquante(s) : %i",(board->nbDame));
        SDL_Surface *textSurface = TTF_RenderText_Solid(xlFont, string, redPen);

        SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, textSurface);


        SDL_RenderCopy(renderer, text, NULL, &pos);

        TTF_CloseFont(xlFont);
        TTF_Quit();

    }
    SDL_RenderPresent(renderer);
}
