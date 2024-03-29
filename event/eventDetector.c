//
// Created by marco on 21/05/2019.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "eventDetector.h"
#include "../draw/draw.h"
#include "../board/board.h"
#include "../board/cellStructure.h"


/*** EVENT FUNCTION ***/
void eventDetector(SDL_Window *pWindow, SDL_Renderer *renderer, Board *board, int* level, int* nbDame) {
    int continuer = 1;
    int fullscreen = 0;
    SDL_Event event;
    int i = -1, j = -1;

    while (continuer) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                continuer = 0;
            case SDL_KEYUP:
                /*** EVENT Fullscreen ***/
                if (event.key.keysym.sym == SDLK_f) {
                    if (fullscreen == 0) {
                        fullscreen = 1;
                        SDL_SetWindowFullscreen(pWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

                        initGameWindows(renderer, board);
                    } else if (fullscreen == 1) {
                        fullscreen = 0;
                        SDL_SetWindowFullscreen(pWindow, 0);

                        initGameWindows(renderer, board);
                    }
                }
                /*** EVENT Reset Window ***/
                if (event.key.keysym.sym == SDLK_r) {
                    SDL_SetRenderDrawColor(renderer, 208, 208, 208, 255);
                    SDL_RenderClear(renderer);
                    board = initBoard(board->size, board->xDecal);

                    initGameWindows(renderer, board);
                }
                break;
            case SDL_MOUSEBUTTONUP:
                /*** EVENT Get Mouse Click Position ***/
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;

                        /*** EVENT IN GAME ***/
                        if ((x >= 814) && (x <= 910) && (y >= 685) && (y <= 720)) {
                            /*** EVENT Reset Window ***/
                            SDL_SetRenderDrawColor(renderer, 208, 208, 208, 255);
                            SDL_RenderClear(renderer);
                            board = initBoard(board->size, board->xDecal);

                            initGameWindows(renderer, board);
                        }else if((x >= 814) && (x <= 910) && (y >= 575) && (y <= 610)) {
                            /*** EVENT Back to Home Menu **/
                            SDL_RenderClear(renderer);
                            if(!initHome(pWindow,renderer,level,nbDame)){
                                continuer=0;
                            }
                            else {
                                board =initBoard(*nbDame,80);
                                initGameWindows(renderer,board);
                            }
                        }else if ((x >= 814) && (x <= 910) && (y >= 630) && (y <= 665)){
                            /*** EVENT Check result  **/
                            if(board->nbDame == 0){
                                switch (drawEndMessage(pWindow,renderer,board,level,nbDame)){
                                    case 0 :
                                        continuer = 0;
                                        break;
                                    case 1 :
                                        SDL_RenderClear(renderer);
                                        if(!initHome(pWindow,renderer,level,nbDame)){
                                            continuer=0;
                                        }
                                        else {
                                            board =initBoard(*nbDame,80);
                                            initGameWindows(renderer,board);
                                        }
                                        break;
                                    case 2 :
                                        SDL_SetRenderDrawColor(renderer, 208, 208, 208, 255);
                                        SDL_RenderClear(renderer);
                                        board = initBoard(board->size, board->xDecal);

                                        initGameWindows(renderer, board);
                                        break;
                                }
                            }else{
                            /** Sinon message erreur **/
                            SDL_Rect pos = {750,300,200,25};
                            SDL_Color white = {208,208,208,255};
                            SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b,
                                                   white.a);
                            SDL_RenderFillRect(renderer, &pos);

                            TTF_Init();
                            TTF_Font *xlFont = TTF_OpenFont("./data/font/RobotoCondensedLight.ttf", 200);

                            SDL_Color redPen = {255, 0, 0};
                            char string[35]="";
                            sprintf(string,"Dame(s) manquante(s) : %i",(board->nbDame));
                            SDL_Surface *textSurface = TTF_RenderText_Solid(xlFont, string, redPen);

                            SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, textSurface);


                            SDL_RenderCopy(renderer, text, NULL, &pos);

                            TTF_CloseFont(xlFont);
                            TTF_Quit();

                        }

                        }else if ((event.motion.x >= board->yDecal) && (event.motion.y >= board->yDecal) &&
                                   (event.motion.x <= board->cells[0][0].size * board->size + board->xDecal &&
                                    (event.motion.y <= board->cells[0][0].size * board->size + board->yDecal))) {

                            getPositionOnBoard(&x, &y, board);

                            if (board->cells[x][y].isEnable == 1 || (board->cells[x][y].isEnable == 0 &&
                                                                     board->cells[x][y].hasDame == 1)) {

                                // On enlève la dame ou ajoute la dame
                                setCellSprite(renderer,x, y, board,1);

                                // On recalcule l'effet des dames présentes
                                // Uniquement si le niveau est à 0
                                if (*level <= 0) {
                                    setPreventSquareHelp(board); // for max help
                                }

                                if (board->cells[x][y].hasDame == 0) {
                                    if (*level <= 1) {
                                        checkDameConflict(board, x, y);
                                    }
                                    setCellSprite(renderer,x, y, board,1);
                                    drawChessboard(renderer, board);
                                    if (*level <= 2) {
                                        drawHelp(renderer, x, y, board);
                                    }
                                    setCellSprite(renderer,x, y, board,1);
                                } else {
                                    drawChessboard(renderer, board);
                                }
                            }
                        }

                }

                break;

            case SDL_MOUSEMOTION:
                /*** EVENT mouse motion***/
                if ((event.motion.x >= board->xDecal) && (event.motion.y >= board->yDecal) &&
                    (event.motion.x <= board->cells[0][0].size * board->size + board->xDecal) &&
                    (event.motion.y <= board->cells[0][0].size * board->size + board->yDecal)) {
                    int x = event.motion.x;
                    int y = event.button.y;


                    getPositionOnBoard(&x, &y, board);

                    if (x != i || j != y) {

                        if (board->cells[x][y].isEnable == 1) {
                            if (board->cells[x][y].hasDame == 0) {
                                i = x;
                                j = y;

                                setCellSprite(renderer,x, y, board,0);
                                // Level 1 and under
                                if (*level <= 1) {
                                    checkDameConflict(board, x, y);
                                }
                                drawChessboard(renderer, board);
                                // Level 2 and under
                                if (*level <= 2) {
                                    drawHelp(renderer, x, y, board);
                                }
                                setCellSprite(renderer,x, y, board,0);
                            } else {
                                drawChessboard(renderer, board);

                                i = x;
                                j = y;
                            }
                        } else {
                            if (i >= 0 && j >= 0) {
                                if (board->cells[i][j].isEnable) {
                                    drawChessboard(renderer, board);

                                    i = x;
                                    j = y;
                                }
                            }
                        }
                    }
                } else {
                    // We leave or we are out of the chess
                    if (i >= 0 && j >= 0) {
                        i = -1;
                        j = -1;

                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                        // Reset conflict to draw clean board
                        resetConflicts(board);
                        drawChessboard(renderer, board);
                    }
                }


        }
    }
}

