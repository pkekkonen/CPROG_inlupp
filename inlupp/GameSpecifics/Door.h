#ifndef Door_h
#define Door_h

#include "System.h"
#include "StaticSprite.h"

class Door: public StaticSprite {
public:
    static Door* getInstance(int x, int y);
    
    void draw() const;
    
    void tick(std::vector<Sprite*> sprites);
    
    ~Door() {SDL_DestroyTexture(texture);}
private:
    Door(int x, int y);
    SDL_Texture* texture;
};

#endif 
