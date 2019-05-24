//
// Created by marco on 24/05/2019.
//

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include "draw.h"

void drawHelp(SDL_Window *pWindow, SDL_Renderer *renderer, int x, int y, Cell **board) {
    // Horizontal / Vertical
    for (int i = 0; i <= 7; i++) {
        if ((i != x)) {
            drawSquareHelp(pWindow, renderer, i, y , board);
        }
        if (i != y) {
            drawSquareHelp(pWindow, renderer, x, i, board);
        }
    }
    // Diagonal haut-gauche + bas-gauche
    int saveX;
    int saveY;

    // Bas droite
    saveX = x + 1;
    saveY = y + 1;
    while (saveX <= 7 && saveY <= 7) {
        drawSquareHelp(pWindow, renderer, saveX, saveY, board);
        saveX++;
        saveY++;
    }

    // Haut droite
    saveX = x + 1;
    saveY = y - 1;
    while (saveX <= 7 && saveY >= 0) {
        drawSquareHelp(pWindow, renderer, saveX, saveY, board);
        saveX++;
        saveY--;
    }
    // Haut gauche
    saveX = x - 1;
    saveY = y - 1;
    while (saveX >= 0 && saveY >= 0) {
        drawSquareHelp(pWindow, renderer, saveX, saveY, board);
        saveX--;
        saveY--;
    }
    // Bas gauche
    saveX = x - 1;
    saveY = y + 1;
    while (saveX >= 0 && saveY <= 7) {
        drawSquareHelp(pWindow, renderer, saveX, saveY, board);
        saveX--;
        saveY++;
    }
}