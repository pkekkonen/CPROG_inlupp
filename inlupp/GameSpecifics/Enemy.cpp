
#include "Enemy.h"

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
            if(Wall* w = dynamic_cast<Wall*>(s)) {
                moveInOtherDir(); }
    //            } else if(AutoDynamicSprite* e = dynamic_cast<AutoDynamicSprite*>(s)) {
    //                if(this != e)
    //                    moveInOtherDir();
    //            }
    if(!ses.isWithinWindow(&rect))
        moveInOtherDir();
}
