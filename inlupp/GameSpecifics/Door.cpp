
#include "Door.h"

Door* Door::getInstance(int x, int y) {
    return new Door(x, y);
}

void Door::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

void Door::tick(std::vector<Sprite*> sprites) {

    
}

Door::Door(int x, int y): StaticSprite(x, y, 1, 1) {
    texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/Game/door.jpg");
    
}
