//
// Created by marco on 28/05/2019.
//

#include "board.h"

void setConflictLine(Cell **board, int xCursor, int yCursor, int xEnd, int yEnd) {
// End correspond to queen which is in conflict with the cursor Queen
    int saveX ;
    int saveY ;

    if (xCursor == xEnd) {
        // Horizontale
        if (yCursor < yEnd) {
            // if conflict is on the right
            for (int i = yCursor; i < yEnd; ++i) {
                board[xCursor][i].isConflict = 1;
            }
        } else {
            // if conflict is on the left
            for (int i = yCursor; i > yEnd; --i) {
                board[xCursor][i].isConflict = 1;
            }
        }
    } else if (yCursor == yEnd) {
        // Verticale
        if (xCursor < xEnd) {
            // if conflict is under
            for (int i = xCursor; i < xEnd; ++i) {
                board[i][yCursor].isConflict = 1;
            }
        } else {
            // if conflict is above
            for (int i = xCursor; i > xEnd; --i) {
                board[i][yCursor].isConflict = 1;
            }
        }
    } else if (xCursor < xEnd) {
        // diago bas droite
        if (yCursor < yEnd) {
            saveX = xCursor;
            saveY = yCursor;
            while (saveX <= xEnd && saveY <= yEnd) {
                board[saveX][saveY].isConflict = 1;
                saveX++;
                saveY++;
            }
        }else if (yCursor > yEnd){
        // diago haut doite
            saveX = xCursor;
            saveY = yCursor;
            while(saveX <= xEnd && saveY >= yEnd) {
                board[saveX][saveY].isConflict = 1;
                saveX++;
                saveY--;
            }
        }
    } else if ( xCursor > xEnd) {
        // diago bas gauche
        if (yCursor < yEnd){
            saveX = xCursor;
            saveY = yCursor;
            while(saveX >= xEnd && saveY <= yEnd) {
                 board[saveX][saveY].isConflict = 1 ;
                 saveX--;
                 saveY++;
            }
        }else if ( yCursor > yEnd){
        // daigo haut gauche
            saveX = xCursor;
            saveY = yCursor;
            while(saveX >= xEnd && saveY >= xEnd) {
                board[saveX][saveY].isConflict = 1;
                saveX--;
                saveY--;
            }
        }
    }
}


