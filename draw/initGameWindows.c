#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "draw.h"
#include "../board/cellStructure.h"
#include "../board/board.h"

//
// Created by Antoine on 28/05/2019.
//

void initGameWindows(SDL_Renderer* renderer, Board *board) {
    SDL_SetRenderDrawColor(renderer, 208, 208, 208, 255);
    SDL_RenderClear(renderer);

    drawChessboard(renderer, board);
    drawResetButton(renderer);
    drawScoreBoard(renderer,board->size);

    TTF_Init();
    TTF_Font *xlFont = TTF_OpenFont("./data/font/RobotoCondensedLight.ttf", 200);

    SDL_Color blackPen = {0, 0, 0};
    SDL_Surface *textSurface = TTF_RenderText_Solid(xlFont, "Dame(s) restante(s) : 8", blackPen);

    SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect pos = {750,100,200,25};


    SDL_RenderCopy(renderer, text, NULL, &pos);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(text);

    TTF_CloseFont(xlFont);
    TTF_Quit();

    SDL_RenderPresent(renderer);
}