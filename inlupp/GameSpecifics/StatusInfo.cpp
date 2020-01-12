#include "StatusInfo.h"
#include <string>


StatusInfo::StatusInfo(): Sprite(sys.getWindowWidthInSquares()-2, 0, 2, 1), isShowing(false){
    SDL_Surface* surf = TTF_RenderText_Solid(sys.smallFont, "", {0,0,0});
    texture = SDL_CreateTextureFromSurface(sys.ren, surf);
    SDL_FreeSurface(surf);
}

StatusInfo::~StatusInfo() {
    SDL_DestroyTexture(texture);
}

void StatusInfo::draw() const{
    if(isShowing) {
        SDL_Rect r = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &r);

    }
}

void StatusInfo::show() {
    isShowing = isShowing? false: true;
}

void StatusInfo::tick(std::vector<Sprite*> sprites) {
    
    int lifes = 0;
    int bullets = 0;
    int keys = 0;
    for(Sprite* s: sprites) {
        if(MainPlayer* m = dynamic_cast<MainPlayer*>(s)) {
            lifes = m->getLifes();
            if(m->hasThing(BULLET))
                bullets = m->getAmountOfCollectable(BULLET);
            if(m->hasThing(KEY))
                keys = m->getAmountOfCollectable(KEY);
        }
    }
    std::string txt = "Lifes: " + std::to_string(lifes) + "\nAmmo:" + std::to_string(bullets) + "\nKeys: " + std::to_string(keys);

    SDL_Surface* surf = TTF_RenderText_Blended_Wrapped(sys.smallFont, txt.c_str(), {0,0,0}, 80);
    SDL_DestroyTexture(texture);
    texture = SDL_CreateTextureFromSurface(sys.ren, surf);
    SDL_FreeSurface(surf);
    
}

StatusInfo* StatusInfo::getInstance() {
    return new StatusInfo();
}
