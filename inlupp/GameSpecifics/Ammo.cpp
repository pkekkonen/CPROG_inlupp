#include "Ammo.h"
#include "MainPlayer.h"
#include "Session.h"

Ammo* Ammo::getInstance(int x, int y) {
    return new Ammo(x, y);
}

void Ammo::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

Ammo::Ammo(int x, int y): CollectableSprite(x, y, 1, 1, BULLET) {
    SDL_Surface* surf = IMG_Load("/Users/paulinakekkonen/Pictures/Game/bullet.jpg");
    Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
    SDL_SetColorKey(surf, true, white);
    texture = SDL_CreateTextureFromSurface(sys.ren, surf);
    SDL_FreeSurface(surf);
    
}
