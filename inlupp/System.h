#ifndef System_h
#define System_h

#include <SDL2/SDL.h>
class System {
public:
    System();
    ~System();
    
    SDL_Window* win;
    SDL_Renderer* ren;
    int const getHeight() {return height;}
    int const getWidth() {return width;}
private:
    int width;
    int height;
    
};

extern System sys;

#endif
