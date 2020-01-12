
#include "Sprite.h"

Sprite::Sprite(int x, int y, int w, int h) : rect{x*40, y*40, w*40, h*40} {
    if(x > 20 || x < 0 || y > 15 || y < 0) //TODO: ändra så det är konstanter för fönster storlek
        throw std::invalid_argument("Sprite created outside of window.");
    else if(w < 0 || h < 0) //TODO: ändra så det är konstanter för fönster storlek
        throw std::invalid_argument("Height and width of sprite must be at least 1.");
}
