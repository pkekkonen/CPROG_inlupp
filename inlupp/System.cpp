
#include "System.h"

System::System() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    win = SDL_CreateWindow("Game", 10, 10, 25*40, 20*40, 0); //TODO: ta reda på vad siffrorna innebär
    ren = SDL_CreateRenderer(win, -1, 0);
    font = TTF_OpenFont("/Library/Fonts/arial.ttf", 20);
    width = 1000;
    height = 800;
}

System::~System() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
}

System sys;
