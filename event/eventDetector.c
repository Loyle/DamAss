//
// Created by marco on 21/05/2019.
//

#include <SDL2/SDL.h>
#include <stdio.h>
#include "eventDetector.h"
#include "../draw/draw.h"
#include "../board/board.h"
#include "../board/cellStructure.h"


/*** EVENT FUNCTION ***/
void eventDetector(SDL_Window *pWindow, SDL_Renderer *renderer, Board *board) {
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
                    } else if (fullscreen == 1) {
                        fullscreen = 0;
                        SDL_SetWindowFullscreen(pWindow, 0);
                        drawChessboard(renderer, board);
                    }
                }
                /*** EVENT Reset Window ***/
                if (event.key.keysym.sym == SDLK_r) {
                    SDL_SetRenderDrawColor(renderer, 208, 208, 208, 255);
                    SDL_RenderClear(renderer);
                    board = initBoard(8, 80, 80);
                    drawChessboard(renderer, board);
                    drawResetButton(renderer);
                }
                break;
            case SDL_MOUSEBUTTONUP:
                /*** EVENT Get Mouse Click Position ***/
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    if ((x >= 814) && (x <= 910) && (y >= 685) && (y <= 720)) {
                        /*** EVENT Reset Window ***/
                        SDL_SetRenderDrawColor(renderer, 208, 208, 208, 255);
                        SDL_RenderClear(renderer);
                        board = initBoard(8, 80, 80);
                        drawChessboard(renderer, board);
                        drawResetButton(renderer);
                    } else if ((event.motion.x >= board->yDecal) && (event.motion.y >= board->yDecal) &&
                               (event.motion.x <= board->cells[0][0].size * board->size + board->xDecal &&
                               (event.motion.y <= board->cells[0][0].size * board->size + board->yDecal ))){

                        getPositionOnBoard(&x, &y, board);

                        if (board->cells[x][y].isEnable == 1 || (board->cells[x][y].isEnable == 0 &&
                            board->cells[x][y].hasDame == 1)) {

                            // On enlève la dame
                            setCellSprite(x, y, board);

                            // On recalcul l'effet des dames présentes
                            setPreventSquareHelp(board); // for max help


                            //checkDameConflict(board, x, y);
                            drawChessboard(renderer, board);
                        }
                        }
                }

                break;

            case SDL_MOUSEMOTION:
                /*** EVENT mouse motion***/
                if ((event.motion.x >= board->xDecal) && (event.motion.y >= board->yDecal) &&
                    (event.motion.x <= board->cells[0][0].size * board->size + board->xDecal ) &&
                    (event.motion.y <= board->cells[0][0].size * board->size + board->yDecal )) {
                    int x = event.motion.x;
                    int y = event.button.y;


                    getPositionOnBoard(&x, &y, board);

                    if (x != i || j != y) {

                        if (board->cells[x][y].isEnable == 1) {
                            if (board->cells[x][y].hasDame == 0) {
                                i = x;
                                j = y;

                                setCellSprite(x, y, board);
                                checkDameConflict(board, x, y);
                                drawChessboard(renderer, board);
                                drawHelp(renderer, x, y, board);
                                setCellSprite(x, y, board);
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
                        drawChessboard(renderer, board);
                    }
                }
        }
    }
}

