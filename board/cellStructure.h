//
// Created by Antoine on 21/05/2019.
//

#ifndef LP25_CELLSTRUCTURE_H
#define LP25_CELLSTRUCTURE_H

typedef struct Cell Cell;
struct Cell {
    int pixelX;
    int pixelY;

    int hasDame;
    int isConflict;
    int isEnable;

    int size;
};

#endif //LP25_CELLSTRUCTURE_H
