#ifndef Ammo_h
#define Ammo_h
#include "CollectableSprite.h"
#include "Game.h"

class Ammo: public CollectableSprite {
public:
    static Ammo* getInstance(int x, int y, int w, int h);
    
    void const draw();
    
    void tick(std::vector<Sprite*> sprites);
    
    ~Ammo() {SDL_DestroyTexture(texture);}
private:
    Ammo(int x, int y, int w, int h);
    SDL_Texture* texture;
};
#endif
