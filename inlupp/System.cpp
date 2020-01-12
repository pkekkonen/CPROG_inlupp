
#include "System.h"

System::System() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    width = 20;
    height = 15;
    win = SDL_CreateWindow("Game", 10, 10, 20*SQUARE_SIZE, 15*SQUARE_SIZE, 0);
    ren = SDL_CreateRenderer(win, -1, 0);
    smallFont = TTF_OpenFont("/Library/Fonts/arial.ttf", 18);
    bigFont = TTF_OpenFont("/Library/Fonts/Times New Roman Bold.ttf", 40);

}

System::~System() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

}

int System::getWindowHeight() const {return height*SQUARE_SIZE;}
int System::getWindowWidth() const {return width*SQUARE_SIZE;}
int System::getWindowHeightInSquares() const {return height;}
int System::getWindowWidthInSquares() const {return width;}

System sys;
