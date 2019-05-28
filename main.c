
#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

#include "event/eventDetector.h"
#include "draw/draw.h"
#include "board/board.h"


void positionOnChessboard(SDL_Window *, SDL_Renderer *, int, int);

void checkDamePosition(int[][8], int, int);


int main(int argc, char **argv) {
    fflush(stdout);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }
    SDL_Window *pWindow = NULL;
    pWindow = SDL_CreateWindow("DamAss", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               1000,
                               800,
                               SDL_WINDOW_SHOWN |
                               SDL_SWSURFACE); // SDL_WINDOW_RESIZABLE pour pouvoir changer taille window
    SDL_Renderer *renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);

    Cell **board = initBoard(8, 80, 80);

    initGameWindows(renderer,board);

    eventDetector(pWindow, renderer, board);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(pWindow);

    SDL_Quit();

    return 0;
}

