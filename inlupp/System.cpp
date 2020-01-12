
#include "System.h"

System::System() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    widthInSquares = 20;
    heightInSquares = 15;
    win = SDL_CreateWindow("Game", 10, 10, widthInSquares*SQUARE_SIZE, heightInSquares*SQUARE_SIZE, 0);
    ren = SDL_CreateRenderer(win, -1, 0);
    smallFont = TTF_OpenFont("/Library/Fonts/arial.ttf", 18);
    bigFont = TTF_OpenFont("/Library/Fonts/Times New Roman Bold.ttf", 40);

}

System::~System() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

}

int System::getWindowHeight() const {return heightInSquares*SQUARE_SIZE;}
int System::getWindowWidth() const {return widthInSquares*SQUARE_SIZE;}
int System::getWindowHeightInSquares() const {return heightInSquares;}
int System::getWindowWidthInSquares() const {return widthInSquares;}

System sys;
