//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../draw/draw.h"
#include "board.h"

void checkDameConflict(Cell ** board,int x, int y ){
    // Horizontal / Vertical
    for (int i = 0; i <= 7; ++i) {
        for (int j = 0; j <= 7; ++j) {
            board[i][j].isConflict = 0;
        }
    }
    for(int i = 0; i <= 7; i++) {
        if ((board[x][i].hasDame == 1)&&(y!=i)){
            board[x][y].isConflict = 1;
            board[x][i].isConflict = 1;
            setConflictLine(board,x,y,x,i);
        }
        if ((board[i][y].hasDame == 1)&&(x!=i)){
            board[x][y].isConflict = 1;
            board[i][y].isConflict = 1;
            setConflictLine(board,x,y,i,y);
        }
    }
    // Diagonal haut-gauche + bas-gauche
    int saveX;
    int saveY;

    // Bas droite
    saveX = x;
    saveY = y;
    while(saveX <= 7 && saveY <= 7) {
        if (board[saveX][saveY].hasDame == 1 && saveX!=x && saveY!=y ){
            board[x][y].isConflict = 1 ;
            board[saveX][saveY].isConflict = 1 ;
            setConflictLine(board,x,y,saveY,saveY);
        }
        saveX++;
        saveY++;
    }

    // Haut droite
    saveX = x;
    saveY = y;
    while(saveX <= 7 && saveY >= 0) {
        if (board[saveX][saveY].hasDame == 1 && saveX!=x && saveY!=y ){
            board[x][y].isConflict = 1 ;
            board[saveX][saveY].isConflict = 1 ;
            setConflictLine(board,x,y,saveX,saveY);

        }
        saveX++;
        saveY--;
    }
    // Haut gauche
    saveX = x;
    saveY = y;
    while(saveX >= 0 && saveY >= 0) {
        if (board[saveX][saveY].hasDame == 1 && saveX!=x && saveY!=y ){
            board[x][y].isConflict = 1 ;
            board[saveX][saveY].isConflict = 1 ;
            setConflictLine(board,x,y,saveX,saveY);

        }
        saveX--;
        saveY--;
    }
    // Bas gauche
    saveX = x;
    saveY = y;
    while(saveX >= 0 && saveY <= 7) {
        if (board[saveX][saveY].hasDame == 1 && saveX!=x && saveY!=y ){
            board[x][y].isConflict = 1 ;
            board[saveX][saveY].isConflict = 1 ;
            setConflictLine(board,x,y,saveX,saveY);
        }
        saveX--;
        saveY++;
    }
}

