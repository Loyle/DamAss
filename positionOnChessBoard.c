//
// Created by marco on 21/05/2019.
//

#include <SDL2/SDL.h>
#include <stdio.h>
#include "draw/draw.h"

/*** FIND POSITION MOUSE ON CHESSBOARD ***/
void positionOnChessboard(SDL_Window* pWindow,SDL_Renderer* renderer ,int x,int y)
{
    switch (x)
    {
        /* Ligne 1 */
        case 80 ... 159 :
            switch(y)
            {
                /* Colonne A*/
                case 80 ... 159 :
                    //drawSprite(pWindow,renderer,80,80,1);
                    printf("Dans A1\n");
                    break;
                case 160 ... 239 :
                    //drawSprite(pWindow,renderer,80,160,1);
                    printf("Dans A2\n");
                    break;
                case 240 ... 319 :
                    //drawSprite(pWindow,renderer,80,240,0);
                    printf("Dans A3\n");
                    break;
                case 320 ... 399 :
                    //drawSprite(pWindow,renderer,80,320,1);
                    printf("Dans A4\n");
                    break;
                case 400 ... 479 :
                    //drawSprite(pWindow,renderer,80,400,0);
                    printf("Dans A5\n");
                    break;
                case 480 ... 559 :
                    //drawSprite(pWindow,renderer,80,480,1);
                    printf("Dans A6\n");
                    break;
                case 560 ... 639 :
                    //drawSprite(pWindow,renderer,80,560,0);
                    printf("Dans A7\n");
                    break;
                case 640 ... 720 :
                    //drawSprite(pWindow,renderer,80,640,1);
                    printf("Dans A8\n");
                    break;
                default :
                    printf("Out\n");
                    break;
            }
            break;
            /* ligne 2*/
        case 160 ... 239 :
            switch(y)
            {
                /* Colonne B*/
                case 80 ... 159 :
                    //drawSprite(pWindow,renderer,160,80,1);
                    printf("Dans B1\n");
                    break;
                case 160 ... 239 :
                    //drawSprite(pWindow,renderer,160,160,0);
                    printf("Dans B2\n");
                    break;
                case 240 ... 319 :
                    //drawSprite(pWindow,renderer,160,240,1);
                    printf("Dans B3\n");
                    break;
                case 320 ... 399 :
                    //drawSprite(pWindow,renderer,160,320,0);
                    printf("Dans B4\n");
                    break;
                case 400 ... 479 :
                    //drawSprite(pWindow,renderer,160,400,1);
                    printf("Dans B5\n");
                    break;
                case 480 ... 559 :
                    //drawSprite(pWindow,renderer,160,480,0);
                    printf("Dans B6\n");
                    break;
                case 560 ... 639 :
                    //drawSprite(pWindow,renderer,160,560,1);
                    printf("Dans B7\n");
                    break;
                case 640 ... 720 :
                    //drawSprite(pWindow,renderer,160,640,0);
                    printf("Dans B8\n");
                    break;
                default :
                    printf("Out\n");
                    break;
            }
            break;
            /* ligne 3*/
        case 240 ... 319 :
            switch(y)
            {
                /* Colonne*/
                case 80 ... 159 :
                    //drawSprite(pWindow,renderer,240,80,0);
                    printf("Dans C1\n");
                    break;
                case 160 ... 239 :
                    //drawSprite(pWindow,renderer,240,160,1);
                    printf("Dans C2\n");
                    break;
                case 240 ... 319 :
                    //drawSprite(pWindow,renderer,240,240,0);
                    printf("Dans C3\n");
                    break;
                case 320 ... 399 :
                    //drawSprite(pWindow,renderer,240,320,1);
                    printf("Dans C4\n");
                    break;
                case 400 ... 479 :
                    //drawSprite(pWindow,renderer,240,400,0);
                    printf("Dans C5\n");
                    break;
                case 480 ... 559 :
                    //drawSprite(pWindow,renderer,240,480,1);
                    printf("Dans C6\n");
                    break;
                case 560 ... 639 :
                    //drawSprite(pWindow,renderer,240,560,0);
                    printf("Dans C7\n");
                    break;
                case 640 ... 720 :
                    //drawSprite(pWindow,renderer,240,640,1);
                    printf("Dans C8\n");
                    break;
                default :
                    printf("Out\n");
                    break;
            }
            break;
            /* ligne 4*/
        case 320 ... 399 :
            switch(y)
            {
                /* Colonne D*/
                case 80 ... 159 :
                    //drawSprite(pWindow,renderer,320,80,1);
                    printf("Dans D1\n");
                    break;
                case 160 ... 239 :
                    //drawSprite(pWindow,renderer,320,160,0);
                    printf("Dans D2\n");
                    break;
                case 240 ... 319 :
                    //drawSprite(pWindow,renderer,320,240,1);
                    printf("Dans D3\n");
                    break;
                case 320 ... 399 :
                    //drawSprite(pWindow,renderer,320,320,0);
                    printf("Dans D4\n");
                    break;
                case 400 ... 479 :
                    //drawSprite(pWindow,renderer,320,400,1);
                    printf("Dans D5\n");
                    break;
                case 480 ... 559 :
                    //drawSprite(pWindow,renderer,320,480,0);
                    printf("Dans D6\n");
                    break;
                case 560 ... 639 :
                    //drawSprite(pWindow,renderer,320,560,1);
                    printf("Dans D7\n");
                    break;
                case 640 ... 720 :
                    //drawSprite(pWindow,renderer,320,640,0);
                    printf("Dans D8\n");
                    break;
                default :
                    printf("Out\n");
                    break;
            }
            break;
            /* ligne 5*/
        case 400 ... 479 :
            switch(y)
            {
                /* Colonne E*/
                case 80 ... 159 :
                    //drawSprite(pWindow,renderer,400,80,0);
                    printf("Dans E1\n");
                    break;
                case 160 ... 239 :
                    //drawSprite(pWindow,renderer,400,160,1);
                    printf("Dans E2\n");
                    break;
                case 240 ... 319 :
                    //drawSprite(pWindow,renderer,400,240,0);
                    printf("Dans E3\n");
                    break;
                case 320 ... 399 :
                    //drawSprite(pWindow,renderer,400,320,1);
                    printf("Dans E4\n");
                    break;
                case 400 ... 479 :
                    //drawSprite(pWindow,renderer,400,400,0);
                    printf("Dans E5\n");
                    break;
                case 480 ... 559 :
                    //drawSprite(pWindow,renderer,400,480,1);
                    printf("Dans E6\n");
                    break;
                case 560 ... 639 :
                    //drawSprite(pWindow,renderer,400,560,0);
                    printf("Dans E7\n");
                    break;
                case 640 ... 720 :
                    //drawSprite(pWindow,renderer,400,640,1);
                    printf("Dans E8\n");
                    break;
                default :
                    printf("Out\n");
                    break;
            }
            break;
            /* ligne 6*/
        case 480 ... 559 :
            switch(y)
            {
                /* Colonne F*/
                case 80 ... 159:
                    //drawSprite(pWindow,renderer,480,80,1);
                    printf("Dans F1\n");
                    break;
                case 160 ... 239 :
                    //drawSprite(pWindow,renderer,480,160,0);
                    printf("Dans F2\n");
                    break;
                case 240 ... 319 :
                    //drawSprite(pWindow,renderer,480,240,1);
                    printf("Dans F3\n");
                    break;
                case 320 ... 399 :
                    //drawSprite(pWindow,renderer,480,320,0);
                    printf("Dans F4\n");
                    break;
                case 400 ... 479 :
                    //drawSprite(pWindow,renderer,480,400,1);
                    printf("Dans F5\n");
                    break;
                case 480 ... 559 :
                    //drawSprite(pWindow,renderer,480,480,0);
                    printf("Dans F6\n");
                    break;
                case 560 ... 639 :
                    //drawSprite(pWindow,renderer,480,560,1);
                    printf("Dans F7\n");
                    break;
                case 640 ... 720 :
                    //drawSprite(pWindow,renderer,480,640,0);
                    printf("Dans F8\n");
                    break;
                default :
                    printf("Out\n");
                    break;
            }
            break;
            /* ligne 7*/
        case 560 ... 639 :
            switch(y)
            {
                /* Colonne H*/
                case 80 ... 159 :
                    //drawSprite(pWindow,renderer,560,80,0);
                    printf("Dans H1\n");
                    break;
                case 160 ... 239 :
                    //drawSprite(pWindow,renderer,560,160,1);
                    printf("Dans H2\n");
                    break;
                case 240 ... 319 :
                    //drawSprite(pWindow,renderer,560,240,0);
                    printf("Dans H3\n");
                    break;
                case 320 ... 399 :
                    //drawSprite(pWindow,renderer,560,320,1);
                    printf("Dans H4\n");
                    break;
                case 400 ... 479 :
                    //drawSprite(pWindow,renderer,560,400,0);
                    printf("Dans H5\n");
                    break;
                case 480 ... 559 :
                    //drawSprite(pWindow,renderer,560,480,1);
                    printf("Dans H6\n");
                    break;
                case 560 ... 639 :
                    //drawSprite(pWindow,renderer,560,560,0);
                    printf("Dans H7\n");
                    break;
                case 640 ... 720 :
                    //drawSprite(pWindow,renderer,560,640,1);
                    printf("Dans H8\n");
                    break;
                default :
                    printf("Out\n");
                    break;
            }
            break;
            /* ligne 8*/
        case 640 ... 720 :
            switch(y)
            {
                /* Colonne H*/
                case 80 ... 159 :
                    //drawSprite(pWindow,renderer,640,80,1);
                    printf("Dans G1\n");
                    break;
                case 160 ... 239 :
                    //drawSprite(pWindow,renderer,640,160,0);
                    printf("Dans G2\n");
                    break;
                case 240 ... 319 :
                    //drawSprite(pWindow,renderer,640,240,1);
                    printf("Dans G3\n");
                    break;
                case 320 ... 399 :
                    //drawSprite(pWindow,renderer,640,320,0);
                    printf("Dans G4\n");
                    break;
                case 400 ... 479 :
                    //drawSprite(pWindow,renderer,640,400,1);
                    printf("Dans G5\n");
                    break;
                case 480 ... 559 :
                    //drawSprite(pWindow,renderer,640,480,0);
                    printf("Dans G6\n");
                    break;
                case 560 ... 639 :
                    //drawSprite(pWindow,renderer,640,560,1);
                    printf("Dans G7\n");
                    break;
                case 640 ... 720 :
                    //drawSprite(pWindow,renderer,640,640,0);
                    printf("Dans G8\n");
                    break;
                default :
                    printf("Out\n");
                    break;
            }
            break;
        default :
            printf("Out\n");
            break;
    }
}
