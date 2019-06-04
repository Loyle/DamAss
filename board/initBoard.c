//
// Created by Antoine on 21/05/2019.
//

#include <stdlib.h>
#include "cellStructure.h"
#include "board.h"

Board* initBoard(int size, int cellSize ,int decal) {
    Cell **cells = malloc(size * sizeof(Cell));

    for(int i = 0; i < size; i++) {
        cells[i] = malloc(size * sizeof(Cell));
    }

    for(int x = 0; x < size; x++) {
        for (int y = 0; y < size; ++y) {
            cells[x][y].pixelX = x * cellSize + decal;
            cells[x][y].pixelY = y * cellSize+ decal;
            cells[x][y].hasDame = 0;
            cells[x][y].isConflict = 0;
            cells[x][y].isEnable = 1;
            cells[x][y].size = cellSize;
        }
    }
    Board* board = malloc(sizeof(Board));
    board->cells = cells;
    board->size = size;
    board->xDecal = decal;
    board->yDecal = decal;

    return board;
}