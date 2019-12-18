#include <iostream>
#include "Session.h"
#include <SDL2_image/SDL_image.h>
#include "System.h"

Session ses;

class Enemy: public MovingSprite {
public:
    static Enemy* getInstance(int x, int y, int width, int height, int speed) {
        return new Enemy(x, y, width, height, speed);
    }
    void const draw() {
        SDL_Rect r = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &r);
    }
    void tick() {
        counter++;
        if(counter % 5 == 0) {
            if(moveRight) {
                rect.x += getSpeed();
                if(rect.x >= 50)
                    moveRight = false;
            } else {
                rect.x -= getSpeed();
                if(rect.x <= 10)
                    moveRight = true;
            }
        }
    }
    
    ~Enemy() {
        SDL_DestroyTexture(texture);
    }
private:
    Enemy(int x, int y, int w, int h, int s): MovingSprite(x, y, w, h, s) {
        texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/downBtn.jpeg");
    }
    int counter = 0;
    SDL_Texture* texture;
    bool moveRight = true;
    
};

class MainPlayer: public MoveableByKeysSprite {
public:
    static MainPlayer* getInstance(int x, int y, int width, int height, int speed) {
        return new MainPlayer(x, y, width, height, speed);
    }
    void const draw() {
        SDL_Rect r = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &r);
    }
    void tick() {

    }
    
    void leftKeyDown() {
        rect.x -= getSpeed();
    }
    
    void rightKeyDown() {
        rect.x += getSpeed();
    }
    
    void downKeyDown() {
        rect.y += getSpeed();
    }
    
    void upKeyDown() {
        rect.y -= getSpeed();
    }
    
    ~MainPlayer() {
        SDL_DestroyTexture(texture);
    }
    
    
private:
    MainPlayer(int x, int y, int w, int h, int s): MoveableByKeysSprite(x, y, w, h, s) {
        texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/upBtn.jpeg");
    }
    int counter = 0;
    SDL_Texture* texture;
    
};


int main(int argc, char** argv) {
    Enemy* e1 = Enemy::getInstance(10, 10, 200, 100, 2);
    Enemy* e2 = Enemy::getInstance(500, 40, 30, 30, 6);
    MainPlayer* m = MainPlayer::getInstance(200, 400, 100, 100, 2);
    ses.addSprite(e1);
    ses.addSprite(e2);
    ses.addMainPlayer(m);
    ses.run();
    return 0;
}

