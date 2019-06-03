//
// Created by marco on 30/05/2019.
//


#include <SDL2/SDL_render.h>
#include "../board/cellStructure.h"


void setPreventSquareHelp(Cell** board, int x , int y){

    int value;

    if (board[x][y].hasDame == 1){
        value = 1;
    }else{
        value = 0;
    }

    for (int i = 0; i <= 7; i++) {
        board[x][i].isEnable = value;
        board[i][y].isEnable = value;
    }
    // Diagonal haut-gauche + bas-gauche
    int saveX;
    int saveY;

    // Bas droite
    saveX = x ;
    saveY = y ;
    while (saveX <= 7 && saveY <= 7) {
        board[saveX][saveY].isEnable = value;
        saveX++;
        saveY++;
    }

    // Haut droite
    saveX = x ;
    saveY = y ;
    while (saveX <= 7 && saveY >= 0) {
        board[saveX][saveY].isEnable = value;
        saveX++;
        saveY--;
    }
    // Haut gauche
    saveX = x ;
    saveY = y ;
    while (saveX >= 0 && saveY >= 0) {
        board[saveX][saveY].isEnable = value;
        saveX--;
        saveY--;
    }
    // Bas gauche
    saveX = x ;
    saveY = y ;
    while (saveX >= 0 && saveY <= 7) {
        board[saveX][saveY].isEnable = value;
        saveX--;
        saveY++;

    }

}
