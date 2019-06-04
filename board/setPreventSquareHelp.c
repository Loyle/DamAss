//
// Created by marco on 30/05/2019.
//


#include <SDL2/SDL_render.h>
#include <stdio.h>
#include "board.h"
#include "cellStructure.h"


void setPreventSquareHelp(Board *board) {
    for (int x = 0; x < board->size; x++) {
        for (int y = 0; y < board->size; y++) {
            board->cells[x][y].isEnable = 1;
        }
    }
    for (int x = 0; x < board->size; x++) {
        for (int y = 0; y < board->size; y++) {
            if (board->cells[x][y].hasDame == 1) {
                for (int i = 0; i < board->size; i++) {
                    board->cells[x][i].isEnable = 0;
                    board->cells[i][y].isEnable = 0;
                }
                // Diagonal haut-gauche + bas-gauche
                int saveX;
                int saveY;

                // Bas droite
                saveX = x;
                saveY = y;
                while (saveX < board->size && saveY < board->size) {
                    board->cells[saveX][saveY].isEnable = 0;
                    saveX++;
                    saveY++;
                }

                // Haut droite
                saveX = x;
                saveY = y;
                while (saveX < board->size && saveY >= 0) {
                    board->cells[saveX][saveY].isEnable = 0;
                    saveX++;
                    saveY--;
                }
                // Haut gauche
                saveX = x;
                saveY = y;
                while (saveX >= 0 && saveY >= 0) {
                    board->cells[saveX][saveY].isEnable = 0;
                    saveX--;
                    saveY--;
                }
                // Bas gauche
                saveX = x;
                saveY = y;
                while (saveX >= 0 && saveY < board->size) {
                    board->cells[saveX][saveY].isEnable = 0;
                    saveX--;
                    saveY++;

                }
            }

        }
    }
}
