#include "MoveableByKeysSprite.h"

void MoveableByKeysSprite::leftKeyDown() {
    prevX = rect.x;
    prevY = rect.y;
    rect.x -= getSpeed();
}

void MoveableByKeysSprite::rightKeyDown() {
    prevX = rect.x;
    prevY = rect.y;
    rect.x += getSpeed();
}

void MoveableByKeysSprite::downKeyDown() {
    prevY = rect.y;
    prevX = rect.x;
    rect.y += getSpeed();
}

void MoveableByKeysSprite::upKeyDown() {
    prevY = rect.y;
    prevX = rect.x;
    rect.y -= getSpeed();
}

void MoveableByKeysSprite::setToPrevPos() {
    rect.x = prevX;
    rect.y = prevY;
}

