#ifndef MoveableByKeysSprite_h
#define MoveableByKeysSprite_h
#include "Sprite.h"
#include "MovingSprite.h"
#include "CollectableSprite.h"
#include <unordered_map>

//TODO: se till att inte kan kopiera eller tilldela

class MoveableByKeysSprite: public MovingSprite {
public:
    //static MoveableByKeysSprite*
    void leftKeyDown();
    void rightKeyDown();
    void downKeyDown();
    void upKeyDown();
    virtual ~MoveableByKeysSprite() {} //TODO: kolla så implementering av desktruktion i hierarki är rätt implementerad
    bool hasThing(CollectType c);
    void addToBag(CollectType c);
protected:
    MoveableByKeysSprite(int x, int y, int w, int h, int speed): MovingSprite(x, y, w, h, speed) {}
private:
    std::unordered_map<CollectType, int> bag;
    
};

#endif /* MoveableByKeysSprite_h */
