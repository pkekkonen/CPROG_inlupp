
#include "Bullet.h"

Bullet* Bullet::getInstance(int x, int y, int speed, Direction dir) {
    return new Bullet(x, y, 1, 1, speed, dir);
}

void Bullet::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

void Bullet::tick(std::vector<Sprite*> sprites) {
    counter++;
    if(counter % 5 == 0) {
        switch(facing) {
            case UP: moveUp(); break;
            case RIGHT: moveRight(); break;
            case DOWN: moveDown(); break;
            case LEFT: moveLeft(); break;
        }
    }
    for(Sprite* s: sprites) {
        if(Collision::collided(getRect(), s->getRect())) {
            if(Enemy* e = dynamic_cast<Enemy*>(s)) {
                ses.removeSprite(e);
                ses.removeSprite(this);

            }
            if(Wall* w = dynamic_cast<Wall*>(s))
                ses.removeSprite(this);

        }
    }
    
    if(!ses.isWithinWindow(&rect))
        ses.removeSprite(this);

}

Bullet::~Bullet() {
    SDL_DestroyTexture(texture);
}

Bullet::Bullet(int x, int y, int w, int h, int s, Direction dir): DynamicSprite(x, y, w, h, s, dir) {
    texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/Game/bullet.png");
}
