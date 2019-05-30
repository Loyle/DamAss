//
// Created by marco on 30/05/2019.
//


#include <SDL2/SDL_render.h>
#include "../board/cellStructure.h"

void setPreventSquareHelp(Cell** board, int x , int y, int isDame){
/* J'ai pas trouvé de nom plus parlant mais c'est pour
l'aide max ou le chess devient gris lorsqu'on pose une dame*/

// Horizontal / Vertical
    for (int i = 0; i <= 7; i++) {
        board[x][i].isEnable = 0;
        board[i][y].isEnable = 0;
        // Diagonal haut-gauche + bas-gauche
        int saveX;
        int saveY;

        // Bas droite
        saveX = x + 1;
        saveY = y + 1;
        while (saveX <= 7 && saveY <= 7) {
            board[saveX][saveY].isEnable = 0;
            saveX++;
            saveY++;
        }

        // Haut droite
        saveX = x + 1;
        saveY = y - 1;
        while (saveX <= 7 && saveY >= 0) {
            board[saveX][saveY].isEnable = 0;
            saveX++;
            saveY--;
        }
        // Haut gauche
        saveX = x - 1;
        saveY = y - 1;
        while (saveX >= 0 && saveY >= 0) {
            board[saveX][saveY].isEnable = 0;
            saveX--;
            saveY--;
        }
        // Bas gauche
        saveX = x - 1;
        saveY = y + 1;
        while (saveX >= 0 && saveY <= 7) {
            board[saveX][saveY].isEnable = 0;
            saveX--;
            saveY++;
        }

    }
}

