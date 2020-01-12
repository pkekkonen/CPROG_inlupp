
#include "AutoDynamicSprite.h"

AutoDynamicSprite* AutoDynamicSprite::getInstance(int x, int y, int width, int height, int speed, Direction d) {
    return new AutoDynamicSprite(x, y, width, height, speed, d);
}


void AutoDynamicSprite::moveInOtherDir() {
    setToPrevPos();
    
    switch (getFacing()) {
        case Up: moveDown(); break;
        case Down: moveUp(); break;
        case Left: moveRight(); break;
        case Right: moveLeft(); break;
    }
    
}

void AutoDynamicSprite::collidedWithWall() {
    moveInOtherDir();
}

AutoDynamicSprite::~AutoDynamicSprite() {
    SDL_DestroyTexture(texture);
}

AutoDynamicSprite::AutoDynamicSprite(int x, int y, int w, int h, int s, Direction d): DynamicSprite(x, y, w, h, s) {
    texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/Game/downBtn.jpeg");
    this -> setFacing(d);
}
