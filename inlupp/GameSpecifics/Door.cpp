
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

Door::Door(int x, int y): Sprite(x, y, 1, 1) {
    SDL_Surface* surf = IMG_Load("/Users/paulinakekkonen/Pictures/Game/door.jpg");
    Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
    SDL_SetColorKey(surf, true, white);
    texture = SDL_CreateTextureFromSurface(sys.ren, surf);
    SDL_FreeSurface(surf);    
}
