//
// Created by marco on 08/06/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../draw/draw.h"
#include "../board/board.h"


int eventEndDetector(SDL_Window* pWindow,SDL_Renderer* renderer,Board* board, int* level,int* nbDame){
    int continuer = 1;
    int fullscreen = 0;
    SDL_Event event;

    while (continuer) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                return 0;
            case SDL_KEYUP:/*** EVENT Fullscreen ***/
                if (event.key.keysym.sym == SDLK_f) {
                    if (fullscreen == 0) {
                        fullscreen = 1;
                        SDL_SetWindowFullscreen(pWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
                        initGameWindows(renderer, board);
                        drawEndMessage(pWindow,renderer,board,level,nbDame);

                    } else if (fullscreen == 1) {
                        fullscreen = 0;
                        SDL_SetWindowFullscreen(pWindow, 0);
                        initGameWindows(renderer, board);
                        drawEndMessage(pWindow,renderer,board,level,nbDame);
                    }
                }
                break;
            case SDL_MOUSEBUTTONUP :
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;

                    /*** Reset/Restart ***/
                    if ((x >= 245) && (x <= 370) && (y >= 530) && (y <= 580)){
                        /*** RESET ***/
                        return 2;
                    }else if ((x >= 620) && (x <= 745) && (y >= 530) && (y <= 580)){
                        /*** MENU ***/
                        return 1;
                    }
                }
        }
    }
}

