
#ifndef Enemy_h
#define Enemy_h

#include "MovingSprite.h"
#include "Game.h"

class Enemy: public MovingSprite {
public:
    static Enemy* getInstance(int x, int y, int width, int height, int speed, int left, int right);
    void const draw();
    void tick(std::vector<Sprite*> sprites);
    
    ~Enemy();
    
private:
    Enemy(int x, int y, int w, int h, int s, int left, int right);
    int counter = 0;
    SDL_Texture* texture;
    int left;
    int right;
};


#endif /* Enemy_h */
