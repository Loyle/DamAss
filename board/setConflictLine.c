//
// Created by marco on 28/05/2019.
//

#include "board.h"

void setConflictLine(Cell **board, int xStart, int yStart, int xEnd, int yEnd) {

    int saveX ;
    int saveY ;

    if (xStart == xEnd) {
        // Horizontale
        if (yStart < yEnd) {
            // if conflict is on the right
            for (int i = yStart; i < yEnd; ++i) {
                board[xStart][i].isConflict = 1;
            }
        } else {
            // if conflict is on the left
            for (int i = yStart; i > yEnd; --i) {
                board[xStart][i].isConflict = 1;
            }
        }
    } else if (yStart == yEnd) {
        // Verticale
        if (xStart < xEnd) {
            // if conflict is under
            for (int i = xStart; i < xEnd; ++i) {
                board[i][yStart].isConflict = 1;
            }
        } else {
            // if conflict is above
            for (int i = xStart; i > xEnd; --i) {
                board[i][yStart].isConflict = 1;
            }
        }
    } else if (xStart < xEnd) {
        // diago bas droite
        if (yStart < yEnd) {
            saveX = xStart;
            saveY = yStart;
            while (saveX <= xEnd && saveY <= yEnd) {
                board[saveX][saveY].isConflict = 1;
                saveX++;
                saveY++;
            }
        }else if (yStart > yEnd){
        // diago haut doite
            saveX = xStart;
            saveY = yStart;
            while(saveX <= xEnd && saveY >= yEnd) {
                board[saveX][saveY].isConflict = 1;
                saveX++;
                saveY--;
            }
        }
    } else if ( xStart > xEnd) {
        // diago bas gauche
        if (yStart < yEnd){
            saveX = xStart;
            saveY = yStart;
            while(saveX >= xEnd && saveY <= xEnd) {
                 board[saveX][saveY].isConflict = 1 ;
                 saveX--;
                 saveY++;
            }
        }else if ( yStart > yEnd){
        // daigo haut gauche
            saveX = xStart;
            saveY = yStart;
            while(saveX >= xEnd && saveY >= xEnd) {
                board[saveX][saveY].isConflict = 1;
                saveX--;
                saveY--;
            }
        }
    }
}


