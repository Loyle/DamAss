//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../board/board.h"
#include "../board/cellStructure.h"
#include "draw.h"

/***DRAW CHESSBOARD***/
void drawChessboard(SDL_Renderer *renderer, Board *board) {
    SDL_Color colorArray[3] = {{251, 217, 126, 255},
                               {89,  39,  3,   255},
                               {96,  96,  96,  255}};  // beige,brown,grey

    for (int x = 0; x < board->size; x++) {
        for (int y = 0; y < board->size; y++) {
            if (board->cells[x][y].isEnable) {
                int colorID = (x + y) % 2;
                SDL_SetRenderDrawColor(renderer, colorArray[colorID].r, colorArray[colorID].g, colorArray[colorID].b,
                                       colorArray[colorID].a);
                SDL_Rect rect = {board->cells[x][y].pixelX, board->cells[x][y].pixelY, board->cells[x][y].size,
                                 board->cells[x][y].size};
                SDL_RenderFillRect(renderer, &rect);
            } else {
                // max help
                SDL_SetRenderDrawColor(renderer, colorArray[2].r, colorArray[2].g, colorArray[2].b,
                                       colorArray[2].a);
                SDL_Rect rect = {board->cells[x][y].pixelX, board->cells[x][y].pixelY, board->cells[x][y].size,
                                 board->cells[x][y].size};
                SDL_RenderFillRect(renderer, &rect);
            }


            // ReDraw dames
            if (board->cells[x][y].hasDame) {

                SDL_Surface *dameSurface;

                if(board->cells[x][y].isEnable == 0) {
                    dameSurface = SDL_LoadBMP("./data/gray_semi_small.bmp");
                }
                else if (board->cells[x][y].isConflict) {
                    dameSurface = SDL_LoadBMP("./data/red_semi_small.bmp");
                }
                else if ((x + y) % 2) {
                    dameSurface = SDL_LoadBMP("./data/brun_semi_small.bmp");
                } else {
                    dameSurface = SDL_LoadBMP("./data/beige_semi_small.bmp");
                }

                SDL_Texture *dameTexture = SDL_CreateTextureFromSurface(renderer, dameSurface);

                SDL_Rect dest = {board->cells[x][y].pixelX, board->cells[x][y].pixelY, board->cells[x][y].size,
                                 board->cells[x][y].size};
                SDL_RenderCopy(renderer, dameTexture, NULL, &dest);
                SDL_RenderPresent(renderer);

                SDL_DestroyTexture(dameTexture);
                SDL_FreeSurface(dameSurface);
            }
        }
    }
    SDL_RenderPresent(renderer);
}
