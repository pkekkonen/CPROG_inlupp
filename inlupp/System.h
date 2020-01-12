#ifndef System_h
#define System_h

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>

class System {
public:
    System();
    ~System();
    
    SDL_Window* win;
    SDL_Renderer* ren;
    int getWindowHeight() const;
    int getWindowWidth() const;
    int getWindowHeightInSquares() const;
    int getWindowWidthInSquares() const;
    TTF_Font* smallFont;
    TTF_Font* bigFont;
    static const int SQUARE_SIZE = 40;
private:
    int widthInSquares;
    int heightInSquares;

};

extern System sys;


#endif
