//
// Created by marco on 30/05/2019.
//


#include <SDL2/SDL_render.h>
#include "draw.h"
#include "../board/cellStructure.h"


void setPreventSquareHelp(Cell **board) {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            board[x][y].isEnable = 1;


            if (board[x][y].hasDame == 1) {
                for (int i = 0; i <= 7; i++) {
                    board[x][i].isEnable = 0;
                    board[i][y].isEnable = 0;
                }
                // Diagonal haut-gauche + bas-gauche
                int saveX;
                int saveY;

                // Bas droite
                saveX = x;
                saveY = y;
                while (saveX <= 7 && saveY <= 7) {
                    board[saveX][saveY].isEnable = 0;
                    saveX++;
                    saveY++;
                }

                // Haut droite
                saveX = x;
                saveY = y;
                while (saveX <= 7 && saveY >= 0) {
                    board[saveX][saveY].isEnable = 0;
                    saveX++;
                    saveY--;
                }
                // Haut gauche
                saveX = x;
                saveY = y;
                while (saveX >= 0 && saveY >= 0) {
                    board[saveX][saveY].isEnable = 0;
                    saveX--;
                    saveY--;
                }
                // Bas gauche
                saveX = x;
                saveY = y;
                while (saveX >= 0 && saveY <= 7) {
                    board[saveX][saveY].isEnable = 0;
                    saveX--;
                    saveY++;

                }
            }
        }
    }
}
