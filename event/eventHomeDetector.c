//
// Created by marco on 05/06/2019.
//

#include <SDL2/SDL.h>
#include <stdio.h>
#include "eventDetector.h"
#include "../draw/draw.h"

int eventHomeDetector(SDL_Window* pWindow, SDL_Renderer *renderer, int* level,int* nbDame){

    int continuer = 1;
    int fullscreen = 0;
    SDL_Event event;

     while(continuer){
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT :
                return 0;
            case SDL_KEYUP:
                /*** EVENT Fullscreen ***/
                if (event.key.keysym.sym == SDLK_f) {
                    if (fullscreen == 0) {
                        fullscreen = 1;
                        SDL_SetWindowFullscreen(pWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
                        initHome(pWindow,renderer,level,nbDame);

                    } else if (fullscreen == 1) {
                        fullscreen = 0;
                        SDL_SetWindowFullscreen(pWindow, 0);
                        initHome(pWindow,renderer,level,nbDame);
                    }
                }
            case SDL_MOUSEBUTTONUP :
                if (event.button.button == SDL_BUTTON_LEFT){
                    int x = event.button.x;
                    int y = event.button.y;
                    printf("x :%i \n y:%i\n\n",x,y);
                    /*** START ***/

                    if ((x >= 315) && (x <= 716) && (y >= 600) && (y <= 762)){
                        continuer=0;
                    }else if ((x >= 62) && (x <= 350) && (y >= 326) && (y <= 367)){
                        /*** DEBUTANT ***/
                        *level = 0;
                    }else if ((x >= 62) && (x <= 398) && (y >= 246) && (y <= 436)){
                        /*** FACILE ***/
                        *level = 1;
                    }else if ((x >= 62) && (x <= 476) && (y >= 473) && (y <= 509)){
                        /*** INTERMEDIAIRE ***/
                        *level = 2;
                    }else if ((x >= 62) && (x <= 548) && (y >= 272) && (y <= 588)){
                        /*** EXPERT ***/
                        *level = 3;
                    }else if ((x >= 862) && (x <= 918) && (y >= 445) && (y <= 490)){
                        /*** PLUS ***/
                        *nbDame = *nbDame + 1;
                        setTextNbDame(pWindow,renderer,level,nbDame);
                    }else if ((x >= 862) && (x <= 918) && (y >= 514) && (y <= 560)){
                        /*** MOINS ***/
                        if (*nbDame>0){
                            *nbDame = *nbDame - 1;
                        }else if(*nbDame<=0){
                            *nbDame = 0;
                        }
                        setTextNbDame(pWindow,renderer,level,nbDame);
                    }
                }
        }
     }
}

