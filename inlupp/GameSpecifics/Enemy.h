
#ifndef Enemy_h
#define Enemy_h
#include "AutoDynamicSprite.h"

class Enemy: public AutoDynamicSprite {
public:
    void draw() const;
    void tick(std::vector<Sprite*> sprites);
private:
    Enemy(int x, int y, int w, int h, int s, Direction d);
    SDL_Texture* texture;
    int counter = 0;
}

#endif
