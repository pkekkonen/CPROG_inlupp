#include "StatusInfo.h"
#include <string>

//TODO: se till att iostream är borta

//TODO: ändra nedan så att man använder konstanter för fönstrets storlek
StatusInfo::StatusInfo(): Sprite(18, 0, 2, 1), isShowing(false){
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
    
    int life = 0;
    int bullets = 0;
    int keys = 0;
    for(Sprite* s: sprites) {
        if(MainPlayer* m = dynamic_cast<MainPlayer*>(s)) {
            life = m->getLife();
            if(m->hasThing(BULLET))
                bullets = m->getAmountOfCollectable(BULLET);
            if(m->hasThing(KEY))
                keys = m->getAmountOfCollectable(KEY);
        }
    }
    std::string txt = "Lifes: " + std::to_string(life) + "\nAmmo:" + std::to_string(bullets) + "\nKeys: " + std::to_string(keys);

    //SDL_Surface* surf = TTF_RenderText_Solid(sys.font, txt.c_str(), {0,0,0});
    SDL_Surface* surf = TTF_RenderText_Blended_Wrapped(sys.smallFont, txt.c_str(), {0,0,0}, 80);
    SDL_DestroyTexture(texture);
    texture = SDL_CreateTextureFromSurface(sys.ren, surf); //tappar pekare till föregående struktur så kan inte städa bort den. Får minnesläcka. Så innan detta måst vi rensa bort tidigare struktur
    SDL_FreeSurface(surf);
    
}

StatusInfo* StatusInfo::getInstance() {
    return new StatusInfo();
}
