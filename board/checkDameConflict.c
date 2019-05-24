//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../draw/draw.h"
#include "board.h"

void checkDameConflict(int board[][8],int x, int y ){
    // Horizontal / Vertical
    for(int i = 0; i <= 7; i++) {
        board[x][i] = board[x][i] + 1;
        board[i][y] = board[i][y] + 1;
    }
    // Diagonal haut-gauche + bas-gauche
    int saveX;
    int saveY;

    // Bas droite
    saveX = x;
    saveY = y;
    while(saveX <= 7 && saveY <= 7) {
        board[saveX][saveY] = board[saveX][saveY] + 1;
        saveX++;
        saveY++;
    }

    // Haut droite
    saveX = x;
    saveY = y;
    while(saveX <= 7 && saveY >= 0) {
        board[saveX][saveY] = board[saveX][saveY] + 1;
        saveX++;
        saveY--;
    }
    // Haut gauche
    saveX = x;
    saveY = y;
    while(saveX >= 0 && saveY >= 0) {
        board[saveX][saveY] = board[saveX][saveY] + 1;
        saveX--;
        saveY--;
    }
    // Bas gauche
    saveX = x;
    saveY = y;
    while(saveX >= 0 && saveY <= 7) {
        board[saveX][saveY] = board[saveX][saveY] + 1;
        saveX--;
        saveY++;
    }

    board[x][y] = board[x][y] - 5;


    printf("[DEBUG] Display result\n");

    /*** DISPLAY ***/
    for(int i=0 ; i<=7 ; i++){
        for (int j=0 ; j<=7 ; j++){
            printf("%i ",board[i][j]);
        }
        printf("\n");
    }
}

