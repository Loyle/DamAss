//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../board/cellStructure.h"
#include "draw.h"

/***DRAW DAME SPRITE***/
void drawSprite(SDL_Window *pWindow, SDL_Renderer *renderer, int x, int y, Cell **board, int isDame) {

    // Draw dame only if there is no dame actually
    if (board[x][y].hasDame == 0) {
        SDL_Surface *spriteDameBeige = SDL_LoadBMP("./data/beige_semi_small.bmp"); /* color = 0*/
        SDL_Surface *spriteDameBrown = SDL_LoadBMP("./data/brun_semi_small.bmp"); /* color = 1*/

        if (spriteDameBeige && spriteDameBrown) {
            SDL_Texture *sDameBeige = SDL_CreateTextureFromSurface(renderer, spriteDameBeige);
            SDL_Texture *sDameBrown = SDL_CreateTextureFromSurface(renderer, spriteDameBrown);

            SDL_Rect dest = {board[x][y].pixelX, board[x][y].pixelY, board[x][y].size, board[x][y].size};
            if ((x + y) % 2) {
                SDL_RenderCopy(renderer, sDameBrown, NULL, &dest);
            } else {
                SDL_RenderCopy(renderer, sDameBeige, NULL, &dest);
            }
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(sDameBeige);
            SDL_DestroyTexture(sDameBrown);
        } else {
            fprintf(stdout, "Échec de chargement du sprite (%s)\n", SDL_GetError());
        }

        // Set that there is a dam
        if (!board[x][y].hasDame)
            board[x][y].hasDame = isDame;

        SDL_FreeSurface(spriteDameBeige);
        SDL_FreeSurface(spriteDameBrown);
    } else if(board[x][y].hasDame == 1 && isDame == 1) {
        // otherwise, we delete the dame
        board[x][y].hasDame = 0;
    }
}