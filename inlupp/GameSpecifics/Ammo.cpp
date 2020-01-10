#include "Ammo.h"

Ammo* Ammo::getInstance(int x, int y, int w, int h) {
    return new Ammo(x, y, w, h);
}

void const Ammo::draw() {
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

Ammo::Ammo(int x, int y, int w, int h): CollectableSprite(x, y, w, h, BULLET) {
    texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/bullet.jpg");
    
}
