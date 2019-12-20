
#include "System.h"

System::System() {
    win = SDL_CreateWindow("Game", 10, 10, 500, 600, 0); //TODO: ta reda på vad siffrorna innebär
    ren = SDL_CreateRenderer(win, -1, 0);
    width = 500;
    height = 600;
}

System::~System() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
}

System sys;
