#ifndef Collectable_h
#define Collectable_h

#include "StaticSprite.h"

enum CollectType {SPEED, BULLET};

class CollectableSprite: public StaticSprite {
public:
    CollectType getCollectType() const {return collectType;}
    ~CollectableSprite() {}
protected:
    CollectableSprite(int x, int y, int w, int h, CollectType c): StaticSprite(x, y, w, h) { collectType = c;}
private:
    CollectType collectType;
};

#endif /* Collectable_h */
