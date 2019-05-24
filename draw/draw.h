//
// Created by marco on 21/05/2019.
//

#ifndef DAMASS_DRAW_H
#define DAMASS_DRAW_H

#include <SDL2/SDL.h>
#include "../board/cellStructure.h"

void drawSprite(SDL_Window*,SDL_Renderer*,int,int,int);
void drawResetButton(SDL_Window*,SDL_Renderer*);
void drawChessboard(SDL_Window*,SDL_Renderer*,Cell **);

#endif //DAMASS_DRAW_H
