#ifndef Wall_hpp
#define Wall_hpp

#include "StaticSprite.h"

class Wall: public StaticSprite {
public:
    static Wall* getInstance(int x, int y, int w, int h);
    void draw() const;
    ~Wall();
private:
    Wall(int x, int y, int w, int h);
    SDL_Texture* texture;
};

#endif
