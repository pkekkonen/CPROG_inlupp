#include <iostream>
#include "Session.h"
#include <SDL2_image/SDL_image.h>
#include "System.h"

Session ses;

class Enemy: public Sprite {
public:
    Enemy* getInstance(int x, int y, int w, int h) {
        return new Enemy(x, y, w, h);
    }
    void const draw() {
        SDL_Rect r = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &r);
    }
    void tick() {
        
    }
    
    ~Enemy() {
        SDL_DestroyTexture(texture);
    }
private:
    Enemy(int x, int y, int w, int h): Sprite(x, y, w, h) {
        texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/downBtn.jpeg");
    }
    SDL_Texture* texture;
    
};


int main(int argc, char** argv) {
    Enemy* e;
    e->Enemy::getInstance(10, 10, 200, 100);
    ses.addSprite(e);
    ses.run();
    return 0;
}

