
#include "Sprite.h"

extern int SQUARE_SIZE;

Sprite::Sprite(int x, int y, int w, int h) : rect{x*40, y*40, w*40, h*40}, startPosX(x*40), startPosY(y*40) {}

SDL_Rect Sprite::getRect() const {
    return rect;
}
