//
// Created by Antoine on 04/06/2019.
//

#include "board.h"
#include "cellStructure.h"

void resolver(Board *board) {
    int start = 0;
    int conti = 0;
    while (start < 7 && conti == 0) {
        for (int x = start; x < board->size; x++) {
            for (int y = 0; y < board->size; y++) {
                setCellSprite(x, y, board);

                checkDameConflict(board, x, y);
                int good = 1;
                for (int i = 0; i < board->size; i++) {
                    for (int j = 0; j < board->size; j++) {
                        if (board->cells[i][j].isConflict) {
                            good = 0;
                        }
                    }
                }

                if (good == 0) {
                    setCellSprite(x, y, board);
                }
            }
        }

        conti = 1;
        nbDame = 0;
        for(int i = 0; i < board->size; i++) {
            for(int j = 0; j < board->size; j++) {
                if(board->cells[i][j].isConflict) {
                    conti = 0;
                }
            }
        }

        start++;
    }
}