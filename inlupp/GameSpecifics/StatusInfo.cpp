#include "StatusInfo.h"
#include <string>

StatusInfo::StatusInfo(): StaticSprite(22, 0, 3, 2), isShowing(false){
    SDL_Surface* surf = TTF_RenderText_Solid(sys.font, "", {0,0,0});
    texture = SDL_CreateTextureFromSurface(sys.ren, surf);
    SDL_FreeSurface(surf);
}

StatusInfo::~StatusInfo() {
    SDL_DestroyTexture(texture);
}

void StatusInfo::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

void StatusInfo::show() {
    if(isShowing)
        ses.removeSprite(this);
    else
        ses.addSprite(this);
    isShowing = isShowing? false: true;
}

void StatusInfo::tick(std::vector<Sprite*> sprites) {
    
    int life = 0;
    int bullets = 0;
    for(Sprite* s: sprites) {
        if(MainPlayer* m = dynamic_cast<MainPlayer*>(s)) {
            life = m->getLife();
            if(m->hasThing(BULLET))
                bullets = m->getAmountOfCollectable(BULLET);
        }
    }
    std::string txt = "Lifes: " + std::to_string(life) + " \nAmmo:" + std::to_string(bullets);

    //SDL_Surface* surf = TTF_RenderText_Solid(sys.font, txt.c_str(), {0,0,0});
    SDL_Surface* surf = TTF_RenderText_Blended_Wrapped(sys.font, txt.c_str(), {0,0,0}, 80);
    SDL_DestroyTexture(texture);
    texture = SDL_CreateTextureFromSurface(sys.ren, surf); //tappar pekare till föregående struktur så kan inte städa bort den. Får minnesläcka. Så innan detta måst vi rensa bort tidigare struktur
    SDL_FreeSurface(surf);
    
}

StatusInfo* StatusInfo::getInstance() {
    return new StatusInfo();
}
