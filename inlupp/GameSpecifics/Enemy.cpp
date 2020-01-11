
#include "Enemy.h"

Enemy* Enemy::getInstance(int x, int y, int width, int height, int speed, int left, int right) {
    return new Enemy(x, y, width, height, speed, left, right);
}

void Enemy::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

void Enemy::tick(std::vector<Sprite*> sprites) {
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

Enemy::~Enemy() {
    SDL_DestroyTexture(texture);
}

Enemy::Enemy(int x, int y, int w, int h, int s, int left, int right): MovingSprite(x, y, w, h, s), left(left), right(right) {
    texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/downBtn.jpeg");
}
