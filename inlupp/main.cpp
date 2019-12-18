#include <iostream>
#include "Session.h"
#include <SDL2_image/SDL_image.h>
#include "System.h"

Session ses;

class Enemy: public Sprite {
public:
    static Enemy* getInstance(int x, int y, int w, int h) {
        return new Enemy(x, y, w, h);
    }
    void const draw() {
        SDL_Rect r = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &r);
    }
    void tick() {
        counter++;
        if(counter % 5 == 0) {
            if(moveRight) {
                rect.x++;
                if(rect.x >= 50)
                    moveRight = false;
            } else {
                rect.x--;
                if(rect.x <= 10)
                    moveRight = true;
            }
        }
    }
    
    ~Enemy() {
        SDL_DestroyTexture(texture);
    }
private:
    Enemy(int x, int y, int w, int h): Sprite(x, y, w, h) {
        texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/downBtn.jpeg");
    }
    int counter = 0;
    SDL_Texture* texture;
    bool moveRight = true;
    
};


int main(int argc, char** argv) {
    Enemy* e = Enemy::getInstance(10, 10, 200, 100);
    ses.addSprite(e);
    ses.run();
    return 0;
}

