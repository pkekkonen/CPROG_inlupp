#ifndef StaticSprite_h
#define StaticSprite_h
#include "Sprite.h"

class StaticSprite: public Sprite {
public:
    virtual ~StaticSprite() {}
    void tick(std::vector<Sprite*> sprites) {}
protected:
    StaticSprite(int x, int y, int w, int h): Sprite(x, y, w, h) {}
    
};

#endif
