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
            // Use automatic max size
            for (int i = 0; i <= 7; ++i) {
                board[xCursor][i].isConflict = 1;
            }
        } else {
            // if conflict is on the left
            for (int i = 7; i >= 0; --i) {
                board[xCursor][i].isConflict = 1;
            }
        }
    } else if (yCursor == yEnd) {
        // Verticale
        if (xCursor < xEnd) {
            // if conflict is under
            for (int i = 0; i <= 7; ++i) {
                board[i][yCursor].isConflict = 1;
            }
        } else {
            // if conflict is above
            for (int i = 7; i >= 0; --i) {
                board[i][yCursor].isConflict = 1;
            }
        }
    }
    else if((xCursor > xEnd && yCursor > yEnd) || (xCursor < xEnd && yCursor < yEnd)) {
        // Diagonale en bas à droite et en haut à gauche
        saveX = xCursor;
        saveY = yCursor;

        while (saveX <= 7 && saveY <= 7) {
            board[saveX][saveY].isConflict = 1;
            saveX++;
            saveY++;
        }

        saveX = xCursor;
        saveY = yCursor;

        while (saveX >= 0 && saveY >= 0) {
            board[saveX][saveY].isConflict = 1;
            saveX--;
            saveY--;
        }

    }
    else if((xCursor < xEnd && yCursor > yEnd) || (xCursor > xEnd && yCursor < yEnd)) {
        // Dragonale en bas à gauche et en haut à droite
        saveX = xCursor;
        saveY = yCursor;

        while (saveX <= 7 && saveY >= 0) {
            board[saveX][saveY].isConflict = 1;
            saveX++;
            saveY--;
        }

        saveX = xCursor;
        saveY = yCursor;

        while (saveX >= 0 && saveY <= 7) {
            board[saveX][saveY].isConflict = 1;
            saveX--;
            saveY++;
        }

    }
}


