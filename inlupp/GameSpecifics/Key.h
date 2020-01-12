
#ifndef Key_h
#define Key_h
#include "CollectableSprite.h"
#include "Game.h"
#include <iostream>

class Key: public CollectableSprite {
public:
    static Key* getInstance(int x, int y);
    
    void draw() const;
    
    void tick(std::vector<Sprite*> sprites);
    
    ~Key() {SDL_DestroyTexture(texture);
        std::cout<< "KEY ENDED" << std::endl;

    }
private:
    Key(int x, int y);
    SDL_Texture* texture;
};


#endif /* Key_h */
