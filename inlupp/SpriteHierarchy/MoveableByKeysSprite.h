#ifndef MoveableByKeysSprite_h
#define MoveableByKeysSprite_h

#include <unordered_map>

#include "CollectableSprite.h"
#include "DynamicSprite.h"


class MoveableByKeysSprite: public DynamicSprite {
public:
    virtual ~MoveableByKeysSprite() {}
    void keyDown(SDL_Keycode key);
    bool hasThing(CollectType c) const;
    void useThing(CollectType c);
    void addToBag(CollectType c);
    int getAmountOfCollectable(CollectType type) const;
    void shoot();
    void move();
    int getLifes() const;
protected:
    MoveableByKeysSprite(int x, int y, int w, int h, int speed, Direction dir, int l): DynamicSprite(x, y, w, h, speed, dir), lifes(l) {}
    std::unordered_map<CollectType, int> bag;
    void setToStartPos();
    Direction directionToMoveIn;
    bool isMoving;
    int lifes;
};

#endif
