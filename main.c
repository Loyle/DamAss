#include <SDL2/SDL.h>

#include <stdio.h>
#include <math.h>

void pause(SDL_Window*,SDL_Renderer*);
void drawSprite(SDL_Window*,SDL_Renderer*,int,int,int);
void drawResetButton(SDL_Window*,SDL_Renderer*);
void drawChessboard(SDL_Window*,SDL_Renderer*);
void positionOnChessboard(SDL_Window*,SDL_Renderer*,int,int);
void checkDamePostion(int[][8],int,int);


int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
    SDL_Window* pWindow = NULL;
    pWindow = SDL_CreateWindow("Chess",SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               1000,
                               800,
                               SDL_WINDOW_SHOWN|SDL_SWSURFACE); // SDL_WINDOW_RESIZABLE pour pouvoir changer taille window
    SDL_Renderer *renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    int board[8][8]={0};

    drawChessboard(pWindow,renderer);
    drawResetButton(pWindow,renderer);
    checkDamePostion(board,4,4);
    pause(pWindow,renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(pWindow);

    SDL_Quit();

    return 0;
}
/*** EVENT FUNCTION ***/
void pause(SDL_Window* pWindow,SDL_Renderer* renderer)
{
    int continuer = 1;
    int fullscreen = 0;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
            case SDL_KEYUP:
                /*** EVENT Fullscreen ***/
                if (event.key.keysym.sym == SDLK_f)
                {
                    if ( fullscreen == 0)
                    {
                        fullscreen = 1;
                        SDL_SetWindowFullscreen(pWindow,SDL_WINDOW_FULLSCREEN_DESKTOP);
                    }
                    else if(fullscreen == 1)
                    {
                        fullscreen = 0;
                        SDL_SetWindowFullscreen(pWindow,0);
                        drawChessboard(pWindow,renderer);
                    }
                }
                /*** EVENT Reset Window ***/
                if ( event.key.keysym.sym == SDLK_r)
                {
                    SDL_SetRenderDrawColor(renderer,0,0,0,255);
                    SDL_RenderClear(renderer);
                    drawChessboard(pWindow,renderer);
                    drawResetButton(pWindow,renderer);

                }
                break;
            case SDL_MOUSEBUTTONUP:
                /*** EVENT Get Mouse Position ***/
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    int x = event.button.x;
                    int y = event.button.y;
                    if (( x>=814)&&(x<=910)&&(y>=685)&&(y<=720))
                    {
                        SDL_SetRenderDrawColor(renderer,0,0,0,255);
                        SDL_RenderClear(renderer);
                        drawChessboard(pWindow,renderer);
                        drawResetButton(pWindow,renderer);
                    }
                    printf("x : %i\n",x);
                    printf("y : %i\n",y);
                    positionOnChessboard(pWindow,renderer,x,y);
                }
                break;
        }
    }
}

/***DRAW DAME SPRITE***/
void drawSprite(SDL_Window* pWindow,SDL_Renderer* renderer,int x,int y,int color)
{
    SDL_Surface* spriteDameBeige = SDL_LoadBMP("./data/beige_semi_small.bmp"); /* color = 0*/
    SDL_Surface* spriteDameBrown = SDL_LoadBMP("./data/brun_semi_small.bmp"); /* color = 1*/

    int X,Y ;
    SDL_GetWindowSize(pWindow,&X,&Y);

    if(color == 0 )
    {
        if ( spriteDameBeige )
        {
            SDL_Texture* sDameBeige = SDL_CreateTextureFromSurface(renderer,spriteDameBeige);
            printf("DRAW\n");
            SDL_Rect dest = {x, y, Y/10, Y/10};
            SDL_RenderCopy(renderer,sDameBeige,NULL,&dest);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(sDameBeige);
        }
        else
        {
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }
    }
    else if (color == 1 )
    {
        if ( spriteDameBrown )
        {
            SDL_Texture* sDameBrown = SDL_CreateTextureFromSurface(renderer,spriteDameBrown);
            printf("DRAW\n");
            SDL_Rect dest = {x, y, Y/10, Y/10};
            SDL_RenderCopy(renderer,sDameBrown,NULL,&dest);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(sDameBrown);
        }
        else
        {
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }
    }
    SDL_FreeSurface(spriteDameBeige);
    SDL_FreeSurface(spriteDameBrown);
}
/*** DRAW RESET BUTTON ***/
void drawResetButton(SDL_Window* pWindow, SDL_Renderer* renderer){
    SDL_Surface* reset = SDL_LoadBMP("./data/RESET.bmp");

    if (reset)
    {
        SDL_Texture* sReset = SDL_CreateTextureFromSurface(renderer,reset);
        SDL_Rect dest = {810,650,100,100};
        SDL_RenderCopy(renderer,sReset,NULL,&dest);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(sReset);
    }else
    {
        fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
    }

}
/***DRAW CHESSBOARD***/
void drawChessboard(SDL_Window* pWindow,SDL_Renderer* renderer)
{
    int X,Y ;
    SDL_GetWindowSize(pWindow,&X,&Y);
    SDL_Color brown = {89, 39, 3, 255};
    SDL_Color beige = {251, 217, 126, 255};

    for(int j=0; j<4; j++)
    {
        /**Odd line pattern**/
        for(int i=0; i<4; i++ )
        {
            SDL_SetRenderDrawColor(renderer, beige.r, beige.g, beige.b, beige.a);
            SDL_Rect rect = {(Y/10)*(2*i+1), (Y/10)*(2*j+1), Y/10, Y/10};
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, brown.r, brown.g, brown.b, brown.a);
            SDL_Rect rect2 = {(Y/5)*(i+1),(Y/10)*(2*j+1),Y/10,Y/10};
            SDL_RenderFillRect(renderer, &rect2);
        }
        /**Even line pattern**/
        for(int i=0; i<4; i++ )
        {
            SDL_SetRenderDrawColor(renderer, brown.r, brown.g, brown.b, brown.a);
            SDL_Rect rect = {(Y/10)*(2*i+1), (Y/5)*(j+1), Y/10, Y/10};
            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, beige.r, beige.g, beige.b, beige.a);
            SDL_Rect rect2 = {(Y/5)*(i+1),(Y/5)*(j+1),Y/10,Y/10};
            SDL_RenderFillRect(renderer, &rect2);
        }
    }
    SDL_RenderPresent(renderer);
}
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
                    drawSprite(pWindow,renderer,80,80,0);
                    printf("Dans A1\n");
                    break;
                case 160 ... 239 :
                    drawSprite(pWindow,renderer,80,160,1);
                    printf("Dans A2\n");
                    break;
                case 240 ... 319 :
                    drawSprite(pWindow,renderer,80,240,0);
                    printf("Dans A3\n");
                    break;
                case 320 ... 399 :
                    drawSprite(pWindow,renderer,80,320,1);
                    printf("Dans A4\n");
                    break;
                case 400 ... 479 :
                    drawSprite(pWindow,renderer,80,400,0);
                    printf("Dans A5\n");
                    break;
                case 480 ... 559 :
                    drawSprite(pWindow,renderer,80,480,1);
                    printf("Dans A6\n");
                    break;
                case 560 ... 639 :
                    drawSprite(pWindow,renderer,80,560,0);
                    printf("Dans A7\n");
                    break;
                case 640 ... 720 :
                    drawSprite(pWindow,renderer,80,640,1);
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
                    drawSprite(pWindow,renderer,160,80,1);
                    printf("Dans B1\n");
                    break;
                case 160 ... 239 :
                    drawSprite(pWindow,renderer,160,160,0);
                    printf("Dans B2\n");
                    break;
                case 240 ... 319 :
                    drawSprite(pWindow,renderer,160,240,1);
                    printf("Dans B3\n");
                    break;
                case 320 ... 399 :
                    drawSprite(pWindow,renderer,160,320,0);
                    printf("Dans B4\n");
                    break;
                case 400 ... 479 :
                    drawSprite(pWindow,renderer,160,400,1);
                    printf("Dans B5\n");
                    break;
                case 480 ... 559 :
                    drawSprite(pWindow,renderer,160,480,0);
                    printf("Dans B6\n");
                    break;
                case 560 ... 639 :
                    drawSprite(pWindow,renderer,160,560,1);
                    printf("Dans B7\n");
                    break;
                case 640 ... 720 :
                    drawSprite(pWindow,renderer,160,640,0);
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
                    drawSprite(pWindow,renderer,240,80,0);
                    printf("Dans C1\n");
                    break;
                case 160 ... 239 :
                    drawSprite(pWindow,renderer,240,160,1);
                    printf("Dans C2\n");
                    break;
                case 240 ... 319 :
                    drawSprite(pWindow,renderer,240,240,0);
                    printf("Dans C3\n");
                    break;
                case 320 ... 399 :
                    drawSprite(pWindow,renderer,240,320,1);
                    printf("Dans C4\n");
                    break;
                case 400 ... 479 :
                    drawSprite(pWindow,renderer,240,400,0);
                    printf("Dans C5\n");
                    break;
                case 480 ... 559 :
                    drawSprite(pWindow,renderer,240,480,1);
                    printf("Dans C6\n");
                    break;
                case 560 ... 639 :
                    drawSprite(pWindow,renderer,240,560,0);
                    printf("Dans C7\n");
                    break;
                case 640 ... 720 :
                    drawSprite(pWindow,renderer,240,640,1);
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
                    drawSprite(pWindow,renderer,320,80,1);
                    printf("Dans D1\n");
                    break;
                case 160 ... 239 :
                    drawSprite(pWindow,renderer,320,160,0);
                    printf("Dans D2\n");
                    break;
                case 240 ... 319 :
                    drawSprite(pWindow,renderer,320,240,1);
                    printf("Dans D3\n");
                    break;
                case 320 ... 399 :
                    drawSprite(pWindow,renderer,320,320,0);
                    printf("Dans D4\n");
                    break;
                case 400 ... 479 :
                    drawSprite(pWindow,renderer,320,400,1);
                    printf("Dans D5\n");
                    break;
                case 480 ... 559 :
                    drawSprite(pWindow,renderer,320,480,0);
                    printf("Dans D6\n");
                    break;
                case 560 ... 639 :
                    drawSprite(pWindow,renderer,320,560,1);
                    printf("Dans D7\n");
                    break;
                case 640 ... 720 :
                    drawSprite(pWindow,renderer,320,640,0);
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
                    drawSprite(pWindow,renderer,400,80,0);
                    printf("Dans E1\n");
                    break;
                case 160 ... 239 :
                    drawSprite(pWindow,renderer,400,160,1);
                    printf("Dans E2\n");
                    break;
                case 240 ... 319 :
                    drawSprite(pWindow,renderer,400,240,0);
                    printf("Dans E3\n");
                    break;
                case 320 ... 399 :
                    drawSprite(pWindow,renderer,400,320,1);
                    printf("Dans E4\n");
                    break;
                case 400 ... 479 :
                    drawSprite(pWindow,renderer,400,400,0);
                    printf("Dans E5\n");
                    break;
                case 480 ... 559 :
                    drawSprite(pWindow,renderer,400,480,1);
                    printf("Dans E6\n");
                    break;
                case 560 ... 639 :
                    drawSprite(pWindow,renderer,400,560,0);
                    printf("Dans E7\n");
                    break;
                case 640 ... 720 :
                    drawSprite(pWindow,renderer,400,640,1);
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
                    drawSprite(pWindow,renderer,480,80,1);
                    printf("Dans F1\n");
                    break;
                case 160 ... 239 :
                    drawSprite(pWindow,renderer,480,160,0);
                    printf("Dans F2\n");
                    break;
                case 240 ... 319 :
                    drawSprite(pWindow,renderer,480,240,1);
                    printf("Dans F3\n");
                    break;
                case 320 ... 399 :
                    drawSprite(pWindow,renderer,480,320,0);
                    printf("Dans F4\n");
                    break;
                case 400 ... 479 :
                    drawSprite(pWindow,renderer,480,400,1);
                    printf("Dans F5\n");
                    break;
                case 480 ... 559 :
                    drawSprite(pWindow,renderer,480,480,0);
                    printf("Dans F6\n");
                    break;
                case 560 ... 639 :
                    drawSprite(pWindow,renderer,480,560,1);
                    printf("Dans F7\n");
                    break;
                case 640 ... 720 :
                    drawSprite(pWindow,renderer,480,640,0);
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
                    drawSprite(pWindow,renderer,560,80,0);
                    printf("Dans H1\n");
                    break;
                case 160 ... 239 :
                    drawSprite(pWindow,renderer,560,160,1);
                    printf("Dans H2\n");
                    break;
                case 240 ... 319 :
                    drawSprite(pWindow,renderer,560,240,0);
                    printf("Dans H3\n");
                    break;
                case 320 ... 399 :
                    drawSprite(pWindow,renderer,560,320,1);
                    printf("Dans H4\n");
                    break;
                case 400 ... 479 :
                    drawSprite(pWindow,renderer,560,400,0);
                    printf("Dans H5\n");
                    break;
                case 480 ... 559 :
                    drawSprite(pWindow,renderer,560,480,1);
                    printf("Dans H6\n");
                    break;
                case 560 ... 639 :
                    drawSprite(pWindow,renderer,560,560,0);
                    printf("Dans H7\n");
                    break;
                case 640 ... 720 :
                    drawSprite(pWindow,renderer,560,640,1);
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
                    drawSprite(pWindow,renderer,640,80,1);
                    printf("Dans G1\n");
                    break;
                case 160 ... 239 :
                    drawSprite(pWindow,renderer,640,160,0);
                    printf("Dans G2\n");
                    break;
                case 240 ... 319 :
                    drawSprite(pWindow,renderer,640,240,1);
                    printf("Dans G3\n");
                    break;
                case 320 ... 399 :
                    drawSprite(pWindow,renderer,640,320,0);
                    printf("Dans G4\n");
                    break;
                case 400 ... 479 :
                    drawSprite(pWindow,renderer,640,400,1);
                    printf("Dans G5\n");
                    break;
                case 480 ... 559 :
                    drawSprite(pWindow,renderer,640,480,0);
                    printf("Dans G6\n");
                    break;
                case 560 ... 639 :
                    drawSprite(pWindow,renderer,640,560,1);
                    printf("Dans G7\n");
                    break;
                case 640 ... 720 :
                    drawSprite(pWindow,renderer,640,640,0);
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

void checkDamePostion(int board[][8],int x, int y ){
    // Horizontal / Vertical
    for(int i = 0; i <= 7; i++) {
        board[x][i] = board[x][i] + 1;
        board[i][y] = board[i][y] + 1;
    }
    // Diagonal haut-gauche + bas-gauche
    int saveX;
    int saveY;

    // Bas droite
    saveX = x;
    saveY = y;
    while(saveX <= 7 && saveY <= 7) {
        board[saveX][saveY] = board[saveX][saveY] + 1;
        saveX++;
        saveY++;
    }

    // Haut droite
    saveX = x;
    saveY = y;
    while(saveX <= 7 && saveY >= 0) {
        board[saveX][saveY] = board[saveX][saveY] + 1;
        saveX++;
        saveY--;
    }
    // Haut gauche
    saveX = x;
    saveY = y;
    while(saveX >= 0 && saveY >= 0) {
        board[saveX][saveY] = board[saveX][saveY] + 1;
        saveX--;
        saveY--;
    }
    // Bas gauche
    saveX = x;
    saveY = y;
    while(saveX >= 0 && saveY <= 7) {
        board[saveX][saveY] = board[saveX][saveY] + 1;
        saveX--;
        saveY++;
    }

    board[x][y] = board[x][y] - 5;


    printf("[DEBUG] Display result\n");

    /*** DISPLAY ***/
    for(int i=0 ; i<=7 ; i++){
        for (int j=0 ; j<=7 ; j++){
            printf("%i ",board[i][j]);
        }
        printf("\n");
    }
}
