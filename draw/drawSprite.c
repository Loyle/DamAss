//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../board/cellStructure.h"
#include "draw.h"

/***DRAW DAME SPRITE***/
void drawSprite(SDL_Renderer *renderer, int x, int y, Cell **board, int isDame) {

    // Draw dame only if there is no dame actually
    if (board[x][y].hasDame == 0) {
        SDL_Surface *spriteDame = SDL_LoadBMP("./data/queen.bmp");

        if (spriteDame) {
            Uint32 colorkey = SDL_MapRGB(spriteDame->format,0,255,0);
            SDL_SetColorKey( spriteDame, SDL_RLEACCEL || spriteDame, colorkey );

            SDL_Texture *sDame = SDL_CreateTextureFromSurface(renderer, spriteDame);

            SDL_Rect dest = {board[x][y].pixelX, board[x][y].pixelY, board[x][y].size, board[x][y].size};
            SDL_RenderCopy(renderer,sDame,NULL,&dest);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(sDame);

        } else {
            fprintf(stdout, "Échec de chargement du sprite (%s)\n", SDL_GetError());
        }

        // Set that there is a queen
        if (!board[x][y].hasDame)
            board[x][y].hasDame = isDame;

        SDL_FreeSurface(spriteDame);

    } else if(board[x][y].hasDame == 1 && isDame == 1) {
        // otherwise, we delete the dame
        board[x][y].hasDame = 0;
    }
}