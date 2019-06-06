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


                    /*** START ***/
                    if ((x >= 315) && (x <= 716) && (y >= 600) && (y <= 762)){
                        continuer=0;

                    }else if ((x >= 60) && (x <= 360) && (y >= 320) && (y <= 370)){
                        /*** DEBUTANT ***/
                        clearSelectedLevel(renderer,*level);
                        *level = 0;
                        SDL_Rect pos = {60,320,300,50};
                        SDL_Color white = {255,255,255,255};
                        SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b,
                                               white.a);
                        SDL_RenderDrawRect(renderer,&pos);

                    }else if ((x >= 60) && (x <= 260) && (y >= 393) && (y <= 433)){
                        /*** FACILE ***/
                        clearSelectedLevel(renderer,*level);
                        *level = 1;
                        SDL_Rect pos = {60,393,200,50};
                        SDL_Color white = {255,255,255,255};
                        SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b,
                                               white.a);
                        SDL_RenderDrawRect(renderer,&pos);
                    }else if ((x >= 60) && (x <= 480) && (y >= 465) && (y <= 515)){
                        /*** INTERMEDIAIRE ***/
                        clearSelectedLevel(renderer,*level);
                        *level = 2;
                        SDL_Rect pos = {60,465,425,50};
                        SDL_Color white = {255,255,255,255};
                        SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b,
                                               white.a);
                        SDL_RenderDrawRect(renderer,&pos);
                    }else if ((x >= 60) && (x <= 275) && (y >= 542) && (y <= 592)){
                        /*** EXPERT ***/
                        clearSelectedLevel(renderer,*level);
                        *level = 3;
                        SDL_Rect pos = {60,542,215,50};
                        SDL_Color white = {255,255,255,255};
                        SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b,
                                               white.a);
                        SDL_RenderDrawRect(renderer,&pos);
                    }else if ((x >= 862) && (x <= 918) && (y >= 445) && (y <= 490)){
                        /*** PLUS ***/
                        *nbDame = *nbDame + 1;
                        setTextNbDame(renderer,nbDame);
                    }else if ((x >= 862) && (x <= 918) && (y >= 514) && (y <= 560)){
                        /*** MOINS ***/
                        if (*nbDame>0){
                            *nbDame = *nbDame - 1;
                        }else if(*nbDame<=0){
                            *nbDame = 0;
                        }
                        setTextNbDame(renderer,nbDame);
                    }
                    SDL_RenderPresent(renderer);

                }
        }
     }
     return 1;
}

