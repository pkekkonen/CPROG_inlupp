#ifndef Sprite_h
#define Sprite_h
#include <SDL2/SDL.h>
#include <vector>
#include "Collision.h"

class Sprite {
public:
    virtual ~Sprite() {}
    virtual void draw() const = 0;
    virtual void tick(std::vector<Sprite*> sprites) = 0;
    SDL_Rect getRect() const { return rect;}
protected:
    Sprite(int x, int y, int w, int h);
    SDL_Rect rect;

private:
    Sprite(const Sprite& other) = delete;
    const Sprite& operator=(const Sprite& other) = delete; //TODO: har vi nu gjort det omöjligt att skapa instanser av subklasser icke dynamiskt?
};

#endif 
