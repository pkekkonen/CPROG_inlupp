#include "MoveableByKeysSprite.h"

void MoveableByKeysSprite::leftKeyDown() {
    prevX = rect.x;
    prevY = rect.y;
    rect.x -= getSpeed();
    facing = Left;
}

void MoveableByKeysSprite::rightKeyDown() {
    prevX = rect.x;
    prevY = rect.y;
    rect.x += getSpeed();
    facing = Right;
}

void MoveableByKeysSprite::downKeyDown() {
    prevY = rect.y;
    prevX = rect.x;
    rect.y += getSpeed();
    facing = Down;
}

void MoveableByKeysSprite::upKeyDown() {
    prevY = rect.y;
    prevX = rect.x;
    rect.y -= getSpeed();
    facing = Up;
}

void MoveableByKeysSprite::setToPrevPos() {
    if(facing == Right || facing == Left)
        rect.x = prevX;
    else if(facing == Up || facing == Down)
        rect.y = prevY;
}
