#include "Label.h"

Label::Label(int x, int y, int w, int h, std::string t): StaticSprite(x, y, w, h), text(t) {
    SDL_Surface* surf = TTF_RenderText_Solid(sys.bigFont, text.c_str(), {0,0,0});
    texture = SDL_CreateTextureFromSurface(sys.ren, surf);
    SDL_FreeSurface(surf);
}

Label::~Label() {
    SDL_DestroyTexture(texture);
}

void Label::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

Label* Label::getInstance(int x, int y, int w, int h, std::string t) {
    return new Label(x, y, w, h, t);
}
