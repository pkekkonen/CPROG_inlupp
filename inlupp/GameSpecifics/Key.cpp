#include "Key.h"

Key* Key::getInstance(int x, int y) {
    return new Key(x, y);
}

void Key::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

Key::Key(int x, int y): CollectableSprite(x, y, 1, 1, KEY) {
    SDL_Surface* surf = IMG_Load("IMAGE_PATH/GameImages/key.jpeg");
    Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
    SDL_SetColorKey(surf, true, white);
    texture = SDL_CreateTextureFromSurface(sys.ren, surf);
    SDL_FreeSurface(surf);
    
}
