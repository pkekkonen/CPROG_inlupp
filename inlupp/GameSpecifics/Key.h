
#ifndef Key_h
#define Key_h

#include "System.h"
#include "CollectableSprite.h"

class Key: public CollectableSprite {
public:
    static Key* getInstance(int x, int y);
    
    void draw() const;
        
    ~Key() {SDL_DestroyTexture(texture); }
private:
    Key(int x, int y);
    SDL_Texture* texture;
};


#endif
