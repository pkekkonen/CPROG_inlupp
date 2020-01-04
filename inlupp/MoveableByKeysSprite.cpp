#include "MoveableByKeysSprite.h"

void MoveableByKeysSprite::leftKeyDown() {
    moveLeft();
}

void MoveableByKeysSprite::rightKeyDown() {
    moveRight();
}

void MoveableByKeysSprite::downKeyDown() {
    moveDown();
}

void MoveableByKeysSprite::upKeyDown() {
    moveUp();
}

//returns false if thing is not present
bool MoveableByKeysSprite::hasThing(CollectType c) {
    if(bag.find(c) == bag.end())
        return false;
    if(--bag[c] == 0)
        bag.erase(c);
    return true;
}

void MoveableByKeysSprite::addToBag(CollectType c) {
    bag[c]++;
}

