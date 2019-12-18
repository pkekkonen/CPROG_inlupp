#ifndef Sprite_h
#define Sprite_h
#include <SDL2/SDL.h>

class Sprite {
public:
    //Sprite();
    virtual ~Sprite() {};
    virtual void const draw() = 0;
    virtual void tick() = 0;
    SDL_Rect getRect() const { return rect;}
protected:
    Sprite(int x, int y, int w, int h) : rect{x, y, w, h} {}
    SDL_Rect rect;
private:
    Sprite(const Sprite& other) = delete;
    const Sprite& operator=(const Sprite& other) = delete; //TODO: har vi nu gjort det omöjligt att skapa instanser av subklasser icke dynamiskt?
};

#endif 
