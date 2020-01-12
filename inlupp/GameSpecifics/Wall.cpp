#include "Wall.h"
#include "Collision.h"
#include "System.h"

Wall* Wall::getInstance(int x, int y, int w, int h) {
    return new Wall(x, y, w, h);
}

void Wall::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

Wall::~Wall() {
    SDL_DestroyTexture(texture);
}

Wall::Wall(int x, int y, int w, int h): Sprite(x,y,w,h) {
    SDL_Surface* surf = IMG_Load("/Users/paulinakekkonen/Pictures/Game/squareBrick.jpg");
    Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
    SDL_SetColorKey(surf, true, white);
    texture = SDL_CreateTextureFromSurface(sys.ren, surf);
    SDL_FreeSurface(surf);
}
