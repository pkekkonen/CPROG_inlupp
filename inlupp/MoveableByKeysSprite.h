#ifndef MoveableByKeysSprite_h
#define MoveableByKeysSprite_h
#include "Sprite.h"

//TODO: se till att inte kan kopiera eller tilldela
class MoveableByKeysSprite: public Sprite {
public:
    //static MoveableByKeysSprite*
    int const getSpeed() {return speed;} //TODO: retunerar rätt va?
    virtual void leftKeyDown() {};
    virtual void rightKeyDown() {};
    virtual void downKeyDown() {};
    virtual void upKeyDown() {};
    virtual ~MoveableByKeysSprite() {}; //TODO: kolla så implementering av desktruktion i hierarki är rätt implementerad
private:
    int speed;
protected:
    MoveableByKeysSprite(int x, int y, int w, int h, int s): Sprite(x, y, w, h), speed(s) {}
};

#endif /* MoveableByKeysSprite_h */
