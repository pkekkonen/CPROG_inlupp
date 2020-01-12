#include "Key.h"

Key* Key::getInstance(int x, int y) {
    return new Key(x, y);
}

void Key::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

void Key::tick(std::vector<Sprite*> sprites) {
//    for(Sprite* s: sprites) {
//        if(Collision::collided(getRect(), s -> getRect()))
//            if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
//                ses.removeSprite(this);
//    }
    
}

Key::Key(int x, int y): CollectableSprite(x, y, 1, 1, KEY) {
    SDL_Surface* surf = IMG_Load("/Users/paulinakekkonen/Pictures/Game/key.jpeg");
    Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
    SDL_SetColorKey(surf, true, white);
    texture = SDL_CreateTextureFromSurface(sys.ren, surf);
    SDL_FreeSurface(surf);
    
}
