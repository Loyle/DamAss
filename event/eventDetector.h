//
// Created by marco on 21/05/2019.
//

#ifndef DAMASS_EVENTDETECTOR_H
#define DAMASS_EVENTDETECTOR_H

#include <SDL2/SDL.h>
#include "../board/board.h"

void eventDetector(SDL_Window*,SDL_Renderer*,Board* board, int* level,int* nbDame);
int eventHomeDetector(SDL_Window*,SDL_Renderer*,int* level, int* nbDame);
int eventEndDetector(SDL_Window*,SDL_Renderer*,Board* board, int* level,int* nbDame);
#endif //DAMASS_EVENTDETECTOR_H
