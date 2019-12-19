#ifndef MoveableByKeysSprite_h
#define MoveableByKeysSprite_h
#include "Sprite.h"

//TODO: se till att inte kan kopiera eller tilldela
class MoveableByKeysSprite: public Sprite {
public:
    //static MoveableByKeysSprite*
    int const getSpeed() {return speed;} //TODO: retunerar rätt va?
    void leftKeyDown();
    void rightKeyDown();
    void downKeyDown();
    void upKeyDown();
    virtual ~MoveableByKeysSprite() {}; //TODO: kolla så implementering av desktruktion i hierarki är rätt implementerad
private:
    int speed;
protected:
    MoveableByKeysSprite(int x, int y, int w, int h, int speed): Sprite(x, y, w, h), speed(speed) {}
};

#endif /* MoveableByKeysSprite_h */
