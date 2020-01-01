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

class Bullet: public MovingSprite {
public:
    static Bullet* getInstance(int x, int y, int speed, Direction dir) {
        return new Bullet(x, y, 10, 10, speed, dir);
    }
    void const draw() {
        SDL_Rect r = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &r);
    }
    void tick(std::vector<Sprite*> sprites) {
        counter++;
        if(counter % 5 == 0) {
            switch(direction) {
                case Up: rect.y -= getSpeed(); break;
                case Right: rect.x += getSpeed(); break;
                case Down: rect.y += getSpeed(); break;
                case Left: rect.x -= getSpeed(); break;
            }
        }
        for(Sprite* s: sprites) {
            if(Collision::collided(this->rect, s->getRect()))
                if(Enemy* e = dynamic_cast<Enemy*>(s))
                    ses.removeSprite(e);
        }
        
        if(rect.x < 0 || rect.x + rect.w > sys.getWidth() || rect.y < 0 || rect.y + rect.h > sys.getHeight())
            ses.removeSprite(this);
        
    }
    
    ~Bullet() {
        SDL_DestroyTexture(texture);
    }
    
private:
    Bullet(int x, int y, int w, int h, int s, Direction dir): MovingSprite(x, y, w, h, s), direction(dir) {
        texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/downBtn.jpeg");
    }
    int counter = 0;
    SDL_Texture* texture;
    Direction direction;
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
    void tick(std::vector<Sprite*> sprites) {
        for(Sprite* s: sprites) {
            if(Collision::collided(this->getRect(), s->getRect())) {
                if(Enemy* e = dynamic_cast<Enemy*>(s)){
                    ses.removeSprite(this);
                }
            }
        }
        if(!ses.isWithinWindow(&rect)) 
            this->setToPrevPos();
        
    }
    
    void shoot() {
        ses.addSprite(Bullet::getInstance(rect.x, rect.y, 6, getFacing()));
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

void addEnemy() {
    Enemy* e2 = Enemy::getInstance(500, 40, 30, 30, 6, 350, 500);
    ses.addSprite(e2);

}

void addMainPlayer() {
    MainPlayer* m = MainPlayer::getInstance(200, 200, 30, 30, 20);
    ses.addSprite(m);
    //TODO: modifiera lösningen så att tillämparen inte behöva binda utan bara kan skicka pointer och objektet?
    ses.addMemberFunction(SDLK_a, std::bind(&MainPlayer::shoot, m));


}

int main(int argc, char** argv) {
    Enemy* e1 = Enemy::getInstance(10, 10, 200, 100, 2, 5, 200);
    ses.addFunction(SDLK_t, addEnemy);
    ses.addFunction(SDLK_n, addMainPlayer);
    ses.addSprite(e1);
    ses.run();
    return 0;
}

