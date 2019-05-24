//
// Created by marco on 21/05/2019.
//

#include <SDL2/SDL.h>
#include <stdio.h>
#include "eventDetector.h"
#include "draw/draw.h"


/*** EVENT FUNCTION ***/
void eventDetector(SDL_Window* pWindow,SDL_Renderer* renderer)
{
    int continuer = 1;
    int fullscreen = 0;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
            case SDL_KEYUP:
                /*** EVENT Fullscreen ***/
                if (event.key.keysym.sym == SDLK_f)
                {
                    if ( fullscreen == 0)
                    {
                        fullscreen = 1;
                        SDL_SetWindowFullscreen(pWindow,SDL_WINDOW_FULLSCREEN_DESKTOP);
                    }
                    else if(fullscreen == 1)
                    {
                        fullscreen = 0;
                        SDL_SetWindowFullscreen(pWindow,0);
                        drawChessboard(pWindow,renderer);
                    }
                }
                /*** EVENT Reset Window ***/
                if ( event.key.keysym.sym == SDLK_r)
                {
                    SDL_SetRenderDrawColor(renderer,0,0,0,255);
                    SDL_RenderClear(renderer);
                    drawChessboard(pWindow,renderer);
                    drawResetButton(pWindow,renderer);

                }
                break;
            case SDL_MOUSEBUTTONUP:
                /*** EVENT Get Mouse Position ***/
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (( x>=814)&&(x<=910)&&(y>=685)&&(y<=720))
                    {
                        SDL_SetRenderDrawColor(renderer,0,0,0,255);
                        SDL_RenderClear(renderer);
                        drawChessboard(pWindow,renderer);
                        drawResetButton(pWindow,renderer);
                    }
                    printf("x : %i\n",x);
                    printf("y : %i\n",y);
                    positionOnChessboard(pWindow,renderer,x,y);
                }
                break;
        }
    }
}
