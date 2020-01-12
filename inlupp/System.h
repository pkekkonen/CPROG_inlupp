#ifndef System_h
#define System_h

#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class System {
public:
    System();
    ~System();
    
    SDL_Window* win;
    SDL_Renderer* ren;
    int getHeightInPixels() const {return height*SQUARE_SIZE;}
    int getWidthInPixels() const {return width*SQUARE_SIZE;}
    int getHeightInTiles() const {return height;}
    int getWidthInTiles() const {return width;}
    TTF_Font* smallFont;
    TTF_Font* bigFont;
    static const int SQUARE_SIZE = 40;
private:
    int width;
    int height;

};

extern System sys;

#endif
