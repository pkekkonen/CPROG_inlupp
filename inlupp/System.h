#ifndef System_h
#define System_h

#include <SDL2/SDL.h>
struct System {
    System();
    ~System();
    
    SDL_Window* win;
    SDL_Renderer* ren;
    
};

extern System sys;

#endif
