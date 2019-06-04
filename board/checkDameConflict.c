//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../draw/draw.h"
#include "board.h"
#include "cellStructure.h"

void checkDameConflict(Board* board,int x, int y ){
    // Horizontal / Vertical
    for (int i = 0; i < board->size; ++i) {
        for (int j = 0; j < board->size; ++j) {
            board->cells[i][j].isConflict = 0;
        }
    }
    for(int i = 0; i < board->size; i++) {
        if ((board->cells[x][i].hasDame == 1)&&(y!=i)){
            board->cells[x][y].isConflict = 1;
            board->cells[x][i].isConflict = 1;
            setConflictLine(board,x,y,x,i);
        }
        if ((board->cells[i][y].hasDame == 1)&&(x!=i)){
            board->cells[x][y].isConflict = 1;
            board->cells[i][y].isConflict = 1;
            setConflictLine(board,x,y,i,y);
        }
    }
    // Diagonal haut-gauche + bas-gauche
    int saveX;
    int saveY;

    // Bas droite
    saveX = x;
    saveY = y;
    while(saveX < board->size && saveY < board->size) {
        if (board->cells[saveX][saveY].hasDame == 1 && saveX!=x && saveY!=y ){
            board->cells[x][y].isConflict = 1 ;
            board->cells[saveX][saveY].isConflict = 1 ;
            setConflictLine(board,x,y,saveY,saveY);
        }
        saveX++;
        saveY++;
    }

    // Haut droite
    saveX = x;
    saveY = y;
    while(saveX < board->size && saveY >= 0) {
        if (board->cells[saveX][saveY].hasDame == 1 && saveX!=x && saveY!=y ){
            board->cells[x][y].isConflict = 1 ;
            board->cells[saveX][saveY].isConflict = 1 ;
            setConflictLine(board,x,y,saveX,saveY);

        }
        saveX++;
        saveY--;
    }
    // Haut gauche
    saveX = x;
    saveY = y;
    while(saveX >= 0 && saveY >= 0) {
        if (board->cells[saveX][saveY].hasDame == 1 && saveX!=x && saveY!=y ){
            board->cells[x][y].isConflict = 1 ;
            board->cells[saveX][saveY].isConflict = 1 ;
            setConflictLine(board,x,y,saveX,saveY);

        }
        saveX--;
        saveY--;
    }
    // Bas gauche
    saveX = x;
    saveY = y;
    while(saveX >= 0 && saveY < board->size) {
        if (board->cells[saveX][saveY].hasDame == 1 && saveX!=x && saveY!=y ){
            board->cells[x][y].isConflict = 1 ;
            board->cells[saveX][saveY].isConflict = 1 ;
            setConflictLine(board,x,y,saveX,saveY);
        }
        saveX--;
        saveY++;
    }
}

