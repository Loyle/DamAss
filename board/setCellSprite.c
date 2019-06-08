//
// Created by marco on 21/05/2019.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include "cellStructure.h"
#include "board.h"
#include "../draw/draw.h"

/*** INVERT HASDAME STATUS ***/
void setCellSprite(SDL_Renderer* renderer,int x, int y, Board *board,int isDame) {

    if(board->cells[x][y].hasDame == 0 && board->nbDame > 0) {
        board->cells[x][y].hasDame = 1;
        if(isDame == 1){
            board->nbDame = board->nbDame - 1;
            drawScoreBoard(renderer,board->nbDame);
        }
    }
    else if(board->cells[x][y].hasDame == 1) {
        // otherwise, we delete the dame
        board->cells[x][y].hasDame = 0;
        if(isDame == 1) {
            board->nbDame = board->nbDame + 1;
            drawScoreBoard(renderer, board->nbDame);
        }
    }
}