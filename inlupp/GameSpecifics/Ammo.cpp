#include "Ammo.h"

Ammo* Ammo::getInstance(int x, int y) {
    return new Ammo(x, y);
}

void Ammo::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

void Ammo::tick(std::vector<Sprite*> sprites) {
    for(Sprite* s: sprites) {
        if(Collision::collided(getRect(), s -> getRect()))
            if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
                ses.removeSprite(this);
    }
    
}

Ammo::Ammo(int x, int y): CollectableSprite(x, y, 1, 1, BULLET) {
    texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/bullet.jpg");
    
}
