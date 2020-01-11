#include "StatusInfo.h"
#include <string>

StatusInfo::StatusInfo(): StaticSprite(24, 0, 1, 1), isShowing(false){
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
    for(Sprite* s: sprites) {
        if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
            life = m->getLife();
    }

    SDL_Surface* surf = TTF_RenderText_Solid(sys.font, (std::to_string(life)).c_str(), {0,0,0});
    SDL_DestroyTexture(texture);
    texture = SDL_CreateTextureFromSurface(sys.ren, surf); //tappar pekare till föregående struktur så kan inte städa bort den. Får minnesläcka. Så innan detta måst vi rensa bort tidigare struktur
    SDL_FreeSurface(surf);
    
}

StatusInfo* StatusInfo::getInstance() {
    return new StatusInfo();
}
