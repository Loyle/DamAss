//
// Created by marco on 01/06/2019.
//

#include <SDL2/SDL_render.h>
#include "../board/cellStructure.h"

void unsetPreventSquareHelp(Cell** board, int x , int y){

// Horizontal / Vertical
    for (int i = 0; i <= 7; i++) {
        board[x][i].isEnable = 1;
        board[i][y].isEnable = 1;
    }
    // Diagonal haut-gauche + bas-gauche
    int saveX;
    int saveY;

    // Bas droite
    saveX = x;
    saveY = y;
    while (saveX <= 7 && saveY <= 7) {
        board[saveX][saveY].isEnable = 1;
        saveX++;
        saveY++;
    }

    // Haut droite
    saveX = x ;
    saveY = y ;
    while (saveX <= 7 && saveY >= 0) {
        board[saveX][saveY].isEnable = 1;
        saveX++;
        saveY--;
    }
    // Haut gauche
    saveX = x ;
    saveY = y ;
    while (saveX >= 0 && saveY >= 0) {
        board[saveX][saveY].isEnable = 1;
        saveX--;
        saveY--;
    }
    // Bas gauche
    saveX = x ;
    saveY = y ;
    while (saveX >= 0 && saveY <= 7) {
        board[saveX][saveY].isEnable = 1;
        saveX--;
        saveY++;
    }

}

