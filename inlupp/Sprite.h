#ifndef Sprite_h
#define Sprite_h
#include <SDL2/SDL.h>

class Sprite {
public:
    //Sprite();
    virtual ~Sprite();
    virtual void mouseButtonDown(int x, int y);
    virtual void mouseButtonUp(int x, int y);
    virtual void leftKeyDown();
    virtual void rightKeyDown();
    virtual void downKeyDown();
    virtual void upKeyDown();
    virtual void draw() const = 0;
    SDL_Rect getRect() const { return rect;}
protected:
    Sprite(int x, int y, int w, int h) : rect{x, y, w, h} {}
    SDL_Rect rect;
};

#endif 
