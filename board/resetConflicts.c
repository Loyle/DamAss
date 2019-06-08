//
// Created by Antoine on 08/06/2019.
//

#include "board.h"
#include "cellStructure.h"

void resetConflicts(Board *board) {
    for(int x = 0; x < board->size; x++) {
        for(int y = 0; y < board->size; y++) {
            board->cells[x][y].isConflict = 0;
        }
    }
}