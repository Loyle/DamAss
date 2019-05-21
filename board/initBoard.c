//
// Created by Antoine on 21/05/2019.
//

#include <stdlib.h>
#include "boxStructure.h"
Box **initBoard(int size, int boxSize) {
    Box **board = malloc(size * sizeof(Box));

    for(int i = 0; i < size; i++) {
        board[i] = malloc(size * sizeof(Box));
    }

    for(int x = 0; x < size; x++) {
        for (int y = 0; y < size; ++y) {
            board[x][y].pixelX = x * boxSize;
            board[x][y].pixelY = y * boxSize;
            board[x][y].asDame = 0;
        }
    }

    return board;
}