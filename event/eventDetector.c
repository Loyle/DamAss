//
// Created by marco on 21/05/2019.
//

#include <SDL2/SDL.h>
#include <stdio.h>
#include "eventDetector.h"
#include "../draw/draw.h"
#include "../board/board.h"


/*** EVENT FUNCTION ***/
void eventDetector(SDL_Window *pWindow, SDL_Renderer *renderer, Cell **board) {
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
                        drawChessboard(pWindow, renderer, board);
                    }
                }
                /*** EVENT Reset Window ***/
                if (event.key.keysym.sym == SDLK_r) {
                    SDL_SetRenderDrawColor(renderer, 208, 208, 208, 255);
                    SDL_RenderClear(renderer);
                    board = initBoard(8, 80, 80);
                    drawChessboard(pWindow, renderer, board);
                    drawResetButton(pWindow, renderer);
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
                        drawChessboard(pWindow, renderer, board);
                        drawResetButton(pWindow, renderer);
                    } else {
                        getPositionOnBoard(&x, &y, board);
                        drawSprite(pWindow, renderer, x, y, board, 1);
                    }
                }
                break;

            case SDL_MOUSEMOTION:
                /*** EVENT mouse motion***/
                if ((event.motion.x >= board[0][0].decal) && (event.motion.y >= board[0][0].decal) &&
                    (event.motion.x <= board[0][0].size * 8 + board[0][0].decal) &&
                    (event.motion.y <= board[0][0].size * 8 + board[0][0].decal)) {
                    int x = event.motion.x;
                    int y = event.button.y;
                    getPositionOnBoard(&x, &y, board);

                    if (i != x || j != y) {
                        // clear l'ancienne case (avec seulement si x et y != -1
                        if ((i >= 0) && (j >= 0)) {
                            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                            //SDL_RenderClear(renderer);
                            drawChessboard(pWindow, renderer, board);
                            //drawResetButton(pWindow,renderer);
                        }
                        i = x;
                        j = y;
                        drawSprite(pWindow, renderer, x, y, board, 0);
                        drawHelp(pWindow, renderer, x, y, board);
                    }
                }
                else {
                    // We leave or we are out of the chest
                    if(i >= 0 && j >= 0) {
                        i = -1;
                        j = -1;

                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                        drawChessboard(pWindow, renderer, board);
                    }
                }
        }
    }
}

