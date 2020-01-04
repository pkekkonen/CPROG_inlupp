#ifndef MoveableByKeysSprite_h
#define MoveableByKeysSprite_h
#include "Sprite.h"
#include "MovingSprite.h"

//TODO: se till att inte kan kopiera eller tilldela

class MoveableByKeysSprite: public MovingSprite {
public:
    //static MoveableByKeysSprite*
    void leftKeyDown();
    void rightKeyDown();
    void downKeyDown();
    void upKeyDown();
    virtual ~MoveableByKeysSprite() {} //TODO: kolla så implementering av desktruktion i hierarki är rätt implementerad
protected:
    MoveableByKeysSprite(int x, int y, int w, int h, int speed): MovingSprite(x, y, w, h, speed) {}
};

#endif /* MoveableByKeysSprite_h */
