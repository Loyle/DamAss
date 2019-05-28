//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../board/cellStructure.h"
#include "draw.h"

/***DRAW CHESSBOARD***/
void drawChessboard(SDL_Renderer *renderer, Cell **board) {
    SDL_Color colorArray[2] = {{251, 217, 126, 255},
                               {89,  39,  3,   255}};  // beige,brown

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; ++y) {
            int colorID = (x + y) % 2;
            SDL_SetRenderDrawColor(renderer, colorArray[colorID].r, colorArray[colorID].g, colorArray[colorID].b,
                                   colorArray[colorID].a);
            SDL_Rect rect = {board[x][y].pixelX, board[x][y].pixelY, board[x][y].size, board[x][y].size};
            SDL_RenderFillRect(renderer, &rect);


            // ReDraw dames
            if (board[x][y].hasDame) {
                SDL_Surface *dameSurface;
                if ((x + y) % 2) {
                    dameSurface = SDL_LoadBMP("./data/brun_semi_small.bmp");
                } else {
                    dameSurface = SDL_LoadBMP("./data/beige_semi_small.bmp");
                }

                SDL_Texture *dameTexture = SDL_CreateTextureFromSurface(renderer, dameSurface);

                SDL_Rect dest = {board[x][y].pixelX, board[x][y].pixelY, board[x][y].size, board[x][y].size};
                SDL_RenderCopy(renderer, dameTexture, NULL, &dest);
                SDL_RenderPresent(renderer);

                SDL_DestroyTexture(dameTexture);
                SDL_FreeSurface(dameSurface);
            }
        }
    }
    SDL_RenderPresent(renderer);
}
