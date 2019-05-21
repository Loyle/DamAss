//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>

/***DRAW CHESSBOARD***/
void drawChessboard(SDL_Window* pWindow,SDL_Renderer* renderer)
{
    int X,Y ;
    SDL_GetWindowSize(pWindow,&X,&Y);
    SDL_Color brown = {89, 39, 3, 255};
    SDL_Color beige = {251, 217, 126, 255};

    for(int j=0; j<4; j++)
    {
        /**Odd line pattern**/
        for(int i=0; i<4; i++ )
        {
            SDL_SetRenderDrawColor(renderer, beige.r, beige.g, beige.b, beige.a);
            SDL_Rect rect = {(Y/10)*(2*i+1), (Y/10)*(2*j+1), Y/10, Y/10};
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, brown.r, brown.g, brown.b, brown.a);
            SDL_Rect rect2 = {(Y/5)*(i+1),(Y/10)*(2*j+1),Y/10,Y/10};
            SDL_RenderFillRect(renderer, &rect2);
        }
        /**Even line pattern**/
        for(int i=0; i<4; i++ )
        {
            SDL_SetRenderDrawColor(renderer, brown.r, brown.g, brown.b, brown.a);
            SDL_Rect rect = {(Y/10)*(2*i+1), (Y/5)*(j+1), Y/10, Y/10};
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, beige.r, beige.g, beige.b, beige.a);
            SDL_Rect rect2 = {(Y/5)*(i+1),(Y/5)*(j+1),Y/10,Y/10};
            SDL_RenderFillRect(renderer, &rect2);
        }
    }
    SDL_RenderPresent(renderer);
}
