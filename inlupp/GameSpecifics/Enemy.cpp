
#include "Enemy.h"

Enemy* Enemy::getInstance(int x, int y, int width, int height, int speed, Direction d) {
    return new Enemy(x, y, width, height, speed, d);
}

void Enemy::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

void Enemy::tick(std::vector<Sprite*> sprites) {
    counter++; //kan ta bort????
    if(counter % 5 == 0) {
        switch (getFacing()) {
            case Up: moveUp();break;
            case Down: moveDown();break;
            case Left: moveLeft();break;
            case Right: moveRight();break;
        }
    }
    for(Sprite* s: sprites)
        if(Collision::collided(s->getRect(), getRect()))
            if(Wall* w = dynamic_cast<Wall*>(s))
                moveInOtherDir();
    
    if(!ses.isWithinWindow(&rect))
        moveInOtherDir();
}


void Enemy::moveInOtherDir() {
    setToPrevPos();
    
    switch (getFacing()) {
        case Up: moveDown(); break;
        case Down: moveUp(); break;
        case Left: moveRight(); break;
        case Right: moveLeft(); break;
    }
    
}


Enemy::~Enemy() {
    SDL_DestroyTexture(texture);
}

Enemy::Enemy(int x, int y, int w, int h, int s, Direction d): MovingSprite(x, y, w, h, s) {
    texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/Game/downBtn.jpeg");
    this -> setFacing(d);
}
