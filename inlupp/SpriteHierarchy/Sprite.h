#ifndef Sprite_h
#define Sprite_h
#include <SDL2/SDL.h>
#include <vector>
#include "Collision.h"

class Sprite {
public:
    //Sprite();
    virtual ~Sprite() {}
    virtual void const draw() = 0;
    virtual void tick(std::vector<Sprite*> sprites) = 0;
    SDL_Rect getRect() const { return rect;}
protected:
    Sprite(int x, int y, int w, int h) : rect{x*40, y*40, w*40, h*40}, prevX(x), prevY(y) {}
    SDL_Rect rect;
    int prevX;
    int prevY;
private:
    Sprite(const Sprite& other) = delete;
    const Sprite& operator=(const Sprite& other) = delete; //TODO: har vi nu gjort det omöjligt att skapa instanser av subklasser icke dynamiskt?
};

#endif 
