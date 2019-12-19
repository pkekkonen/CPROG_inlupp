#include "MoveableByKeysSprite.h"

void MoveableByKeysSprite::leftKeyDown() {
    rect.x -= getSpeed();
}

void MoveableByKeysSprite::rightKeyDown() {
    rect.x += getSpeed();
}

void MoveableByKeysSprite::downKeyDown() {
    rect.y += getSpeed();
}

void MoveableByKeysSprite::upKeyDown() {
    rect.y -= getSpeed();
}
