#ifndef Collectable_h
#define Collectable_h

#include "Sprite.h"

enum CollectType {BULLET, KEY};

class CollectableSprite: public Sprite {
public:
    CollectType getCollectType() const {return collectType;}
    ~CollectableSprite() {}
protected:
    CollectableSprite(int x, int y, int w, int h, CollectType c): Sprite(x, y, w, h) {
        collectType = c;
    }
private:
    CollectType collectType;
};

#endif
