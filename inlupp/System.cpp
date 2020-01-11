
#include "System.h"

System::System() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    win = SDL_CreateWindow("Game", 10, 10, 20*40, 15*40, 0); 
    ren = SDL_CreateRenderer(win, -1, 0);
    smallFont = TTF_OpenFont("/Library/Fonts/arial.ttf", 20);
    bigFont = TTF_OpenFont("/Library/Fonts/arial.ttf", 40);
    width = 20;
    height = 15;
}

System::~System() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

}

System sys;
