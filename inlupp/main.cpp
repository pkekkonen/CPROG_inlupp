#include <iostream>
#include "Session.h"
#include <SDL2_image/SDL_image.h>
#include "System.h"
#include <vector>

Session ses;

class Enemy: public MovingSprite {
public:
    static Enemy* getInstance(int x, int y, int width, int height, int speed, int left, int right) {
        return new Enemy(x, y, width, height, speed, left, right);
    }
    void const draw() {
        SDL_Rect r = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &r);
    }
    void tick(std::vector<Sprite*> sprites) {
        counter++;
        if(counter % 5 == 0) {
            if(moveRight) {
                rect.x += getSpeed();
                if(rect.x >= right)
                    moveRight = false;
            } else {
                rect.x -= getSpeed();
                if(rect.x <= left)
                    moveRight = true;
            }
        }
        for(Sprite* s: sprites) {
            if(Collision::collided(this->getRect(), s->getRect())) {
                if(MoveableByKeysSprite* m = dynamic_cast<MoveableByKeysSprite*>(s)){
                    
                }
            }
        }
    }
    
    ~Enemy();

private:
    Enemy(int x, int y, int w, int h, int s, int left, int right): MovingSprite(x, y, w, h, s), left(left), right(right) {
        texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/downBtn.jpeg");
    }
    int counter = 0;
    SDL_Texture* texture;
    bool moveRight = true;
    int left;
    int right;
};

Enemy::~Enemy() {
    SDL_DestroyTexture(texture);
}

class MainPlayer: public MoveableByKeysSprite {
public:
    static MainPlayer* getInstance(int x, int y, int width, int height, int speed) {
        return new MainPlayer(x, y, width, height, speed);
    }
    void const draw() {
        SDL_Rect r = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &r);
    }
    void tick(std::vector<Sprite*> sprites) {

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
    Enemy* e1 = Enemy::getInstance(10, 10, 200, 100, 2, 5, 200);
    Enemy* e2 = Enemy::getInstance(500, 40, 30, 30, 6, 350, 500);
    MainPlayer* m = MainPlayer::getInstance(200, 200, 30, 30, 20);
    ses.addSprite(e1);
    ses.addSprite(e2);
    ses.addMainPlayer(m);
    ses.run();
    return 0;
}

