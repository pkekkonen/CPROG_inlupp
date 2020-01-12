#ifndef Ammo_h
#define Ammo_h
#include "CollectableSprite.h"

class Ammo: public CollectableSprite {
public:
    static Ammo* getInstance(int x, int y);
    
    void draw() const;
    
    void tick(std::vector<Sprite*> sprites);
    
    ~Ammo() {SDL_DestroyTexture(texture);}
private:
    Ammo(int x, int y);
    SDL_Texture* texture;
};
#endif
