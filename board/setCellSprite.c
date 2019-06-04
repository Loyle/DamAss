//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "cellStructure.h"
#include "board.h"

/*** INVERT HASDAME STATUS ***/
void setCellSprite(int x, int y, Cell **board) {
    if(board[x][y].hasDame == 0) {
        board[x][y].hasDame = 1;
    }
    else if(board[x][y].hasDame == 1) {
        // otherwise, we delete the dame
        board[x][y].hasDame = 0;
    }
}