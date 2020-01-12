
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
            case UP: moveUp();break;
            case DOWN: moveDown();break;
            case LEFT: moveLeft();break;
            case RIGHT: moveRight();break;
        }
    }
    for(Sprite* s: sprites)
        if(Collision::collided(s->getRect(), getRect()))
            if(Wall* w = dynamic_cast<Wall*>(s)) {
                moveInOtherDir(); }

    if(!ses.isWithinWindow(&rect))
        moveInOtherDir();
}


void Enemy::moveInOtherDir() {
    setToPrevPos();
    
    switch (getFacing()) {
        case UP: moveDown(); break;
        case DOWN: moveUp(); break;
        case LEFT: moveRight(); break;
        case RIGHT: moveLeft(); break;
    }
    
}


Enemy::~Enemy() {
    SDL_DestroyTexture(texture);
}

Enemy::Enemy(int x, int y, int w, int h, int s, Direction d): DynamicSprite(x, y, w, h, s) {
    texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/Game/downBtn.jpeg");
    this -> setFacing(d);
}
