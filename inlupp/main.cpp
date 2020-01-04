#include <iostream>
#include "Session.h"
#include <SDL2_image/SDL_image.h>
#include "System.h"
#include <vector>
#include "StaticSprite.h"

Session ses;

class MainPlayer: public MoveableByKeysSprite {
public:
    static MainPlayer* getInstance(int x, int y, int width, int height, int speed) {
        return new MainPlayer(x, y, width, height, speed);
    }
    void const draw();
    void tick(std::vector<Sprite*> sprites);
    
    void shoot();
    
    
    
    ~MainPlayer();
    
private:
    MainPlayer(int x, int y, int w, int h, int s);
    int counter = 0;
    SDL_Texture* texture;
    
};

class Ammo: public CollectableSprite {
public:
    static Ammo* getInstance(int x, int y, int w, int h) {
        return new Ammo(x, y, w, h);
    }
    
    void const draw() {
        SDL_Rect r = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &r);
    }
    
    void tick(std::vector<Sprite*> sprites) {
            for(Sprite* s: sprites) {
                if(Collision::collided(getRect(), s -> getRect()))
                    if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
                        ses.removeSprite(this);
        }
        
    }
    ~Ammo() {SDL_DestroyTexture(texture);}
private:
    Ammo(int x, int y, int w, int h): CollectableSprite(x, y, w, h, BULLET) { texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/bullet.jpg");}
    SDL_Texture* texture;
};

class Wall: public StaticSprite {
public:
    static Wall* getInstance(int x, int y, int w, int h) {
        return new Wall(x, y, w, h);
    }
    void const draw() {
        SDL_Rect r = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &r);
    }
    ~Wall() {
        SDL_DestroyTexture(texture);
    }
    
    void tick(std::vector<Sprite*> sprites) {
        for(Sprite* s : sprites) {
            if(Collision::collided(this->rect, s-> getRect())) {
            }
        }
    }
private:
    Wall(int x, int y, int w, int h): StaticSprite(x,y,w,h) {
        texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/squareBrick.jpg");
    }
    SDL_Texture* texture;
};

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
            if(getFacing() == Right) {
                moveRight();
                if(rect.x >= right)
                    setFacing(Left);
            } else {
                moveLeft();
                if(rect.x <= left)
                    setFacing(Right);
            }
        }
        for(Sprite* s: sprites) {
            if(Collision::collided(s->getRect(), getRect()))
                if(Wall* w = dynamic_cast<Wall*>(s)) {
                    if(getFacing() == Right)
                        setFacing(Left);
                    else if(getFacing() == Left)
                        setFacing(Right);
                    setToPrevPos();
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
    int left;
    int right;
};

Enemy::~Enemy() {
    SDL_DestroyTexture(texture);
}


class Bullet: public MovingSprite {
public:
    static Bullet* getInstance(int x, int y, int speed, Direction dir) {
        return new Bullet(x/Session::SQUARE_SIZE, y/Session::SQUARE_SIZE, 1, 1, speed, dir);
        //TODO: vackrare lösning
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
            if(Collision::collided(this->rect, s->getRect())) {
                if(Enemy* e = dynamic_cast<Enemy*>(s)) {
                    ses.removeSprite(e);
                    ses.removeSprite(this);
                }
                if(Wall* w = dynamic_cast<Wall*>(s))
                    ses.removeSprite(this);
            }
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


void const MainPlayer::draw() {
        SDL_Rect r = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &r);
    }

void MainPlayer::tick(std::vector<Sprite*> sprites) {
        for(Sprite* s: sprites) {
            if(Collision::collided(this->getRect(), s->getRect())) {
                if(Enemy* e = dynamic_cast<Enemy*>(s)){
                    ses.removeSprite(this);
                } else if(Wall* w = dynamic_cast<Wall*>(s)){
                    this -> setToPrevPos();
                } else if(CollectableSprite* c = dynamic_cast<CollectableSprite*>(s)) {
                    this -> addToBag(c->getCollectType());
                }
                
            }
        }
        if(!ses.isWithinWindow(&rect)) 
            this->setToPrevPos();
        
    }
    
void MainPlayer::shoot() {
        if(this->hasThing(BULLET))
            ses.addSprite(Bullet::getInstance(rect.x, rect.y, 6, getFacing()));
    }
    

    
MainPlayer::~MainPlayer() {
        SDL_DestroyTexture(texture);
    }
    
MainPlayer::MainPlayer(int x, int y, int w, int h, int s): MoveableByKeysSprite(x, y, w, h, s) {
        texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/upBtn.jpeg");
    }



void addEnemy() {
    Enemy* e2 = Enemy::getInstance(10, 1, 1, 1, 10, 1, 500);
    ses.addSprite(e2);

}

void addMainPlayer() {
    MainPlayer* m = MainPlayer::getInstance(5, 5, 1, 1, 40);
    ses.addSprite(m);
    //TODO: modifiera lösningen så att tillämparen inte behöva binda utan bara kan skicka pointer och objektet?
    ses.addMemberFunction(SDLK_a, std::bind(&MainPlayer::shoot, m));


}

int main(int argc, char** argv) {
    Enemy* e1 = Enemy::getInstance(0, 0, 2, 2, 20, 0, 400);
    ses.addFunction(SDLK_t, addEnemy);
    ses.addFunction(SDLK_n, addMainPlayer);
    for(int i = 0; i < 6; i++)
        ses.addSprite(Wall::getInstance(8, i, 1, 1));
    for(int i = 0; i < 7; i++)
        ses.addSprite(Wall::getInstance(3+i, 6, 1, 1));
    ses.addSprite(e1);
    ses.addSprite(Ammo::getInstance(10, 10, 1, 1));
    ses.addSprite(Ammo::getInstance(12, 15, 1, 1));
    ses.run();
    return 0;
}

