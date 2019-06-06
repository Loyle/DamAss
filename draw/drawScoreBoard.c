//
// Created by Antoine on 28/05/2019.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "draw.h"

void drawScoreBoard(SDL_Renderer *renderer, int rest) {


    SDL_Rect pos = {750,100,200,25};
    SDL_Color white = {208,208,208,255};
    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b,
                           white.a);
    SDL_RenderFillRect(renderer, &pos);


    TTF_Init();
    TTF_Font *xlFont = TTF_OpenFont("./data/font/RobotoCondensedLight.ttf", 200);

    SDL_Color blackPen = {0, 0, 0};
    char string[35]="";
    sprintf(string,"Dame(s) restante(s) : %i",rest);
    SDL_Surface *textSurface = TTF_RenderText_Solid(xlFont, string, blackPen);

    SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, textSurface);



    SDL_RenderCopy(renderer, text, NULL, &pos);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(text);

    TTF_CloseFont(xlFont);
    TTF_Quit();

    SDL_RenderPresent(renderer);
}