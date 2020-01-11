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
    int getHeightInPixels() const {return height*40;}
    int getWidthInPixels() const {return width*40;}
    int getHeightInTiles() const {return height;}
    int getWidthInTiles() const {return width;}
    TTF_Font* smallFont;
    TTF_Font* bigFont;
private:
    int width;
    int height;
    
};

extern System sys;

#endif
