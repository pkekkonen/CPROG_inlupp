#ifndef Component_h
#define Component_h
#include <SDL2/SDL.h>

class Component {
public:
    //Component();
    virtual ~Component();
    virtual void mouseButtonDown(int x, int y);
    virtual void mouseButtonUp(int x, int y);
    virtual void draw() const = 0;
    SDL_Rect getRect() const { return rect;}
protected:
    Component(int x, int y, int w, int h) : rect{x,y,w,h} {}
    SDL_Rect rect;
};

#endif
