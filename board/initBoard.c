//
// Created by Antoine on 21/05/2019.
//

#include <stdlib.h>
#include "cellStructure.h"
Cell **initBoard(int size, int cellSize) {
    Cell **board = malloc(size * sizeof(Cell));

    for(int i = 0; i < size; i++) {
        board[i] = malloc(size * sizeof(Cell));
    }

    for(int x = 0; x < size; x++) {
        for (int y = 0; y < size; ++y) {
            board[x][y].pixelX = x * cellSize;
            board[x][y].pixelY = y * cellSize;
            board[x][y].hasDame = 0;
            board[x][y].size = cellSize;
        }
    }

    return board;
}