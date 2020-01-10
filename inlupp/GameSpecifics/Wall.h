#ifndef Wall_hpp
#define Wall_hpp

#include "StaticSprite.h"
#include "Game.h"

class Wall: public StaticSprite {
public:
    static Wall* getInstance(int x, int y, int w, int h);
    void const draw();
    ~Wall();
    
    void tick(std::vector<Sprite*> sprites);
private:
    Wall(int x, int y, int w, int h);
    SDL_Texture* texture;
};

#endif
