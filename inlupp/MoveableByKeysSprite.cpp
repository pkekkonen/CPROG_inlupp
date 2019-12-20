#include "MoveableByKeysSprite.h"

void MoveableByKeysSprite::leftKeyDown() {
    prevX = rect.x;
    rect.x -= getSpeed();
}

void MoveableByKeysSprite::rightKeyDown() {
    prevX = rect.x;
    rect.x += getSpeed();
}

void MoveableByKeysSprite::downKeyDown() {
    prevY = rect.y;
    rect.y += getSpeed();
}

void MoveableByKeysSprite::upKeyDown() {
    prevY = rect.y;
    rect.y -= getSpeed();
}

void MoveableByKeysSprite::setToPrevXPos() {
    rect.x = prevX;
}

void MoveableByKeysSprite::setToPrevYPos() {
    rect.y = prevY;
}
