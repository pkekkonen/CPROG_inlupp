#ifndef System_h
#define System_h

#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL.h>
class System {
public:
    System();
    ~System();
    
    SDL_Window* win;
    SDL_Renderer* ren;
    int getHeight() const {return height;}
    int getWidth() const {return width;}
    TTF_Font* font;
private:
    int width;
    int height;
    
};

extern System sys;

#endif
