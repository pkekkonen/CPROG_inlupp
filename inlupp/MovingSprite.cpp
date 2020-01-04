#include "MovingSprite.h"

void MovingSprite::setToPrevPos() {
    if(facing == Right || facing == Left)
        rect.x = prevX;
    else if(facing == Up || facing == Down)
        rect.y = prevY;
}

void MovingSprite::moveRight() {
    prevX = rect.x;
    prevY = rect.y;
    rect.x += getSpeed();
    facing = Right;
}

void MovingSprite::moveLeft() {
    prevX = rect.x;
    prevY = rect.y;
    rect.x -= getSpeed();
    facing = Left;
}

void MovingSprite::moveDown() {
    prevY = rect.y;
    prevX = rect.x;
    rect.y += getSpeed();
    facing = Down;
}
void MovingSprite::moveUp() {
    prevY = rect.y;
    prevX = rect.x;
    rect.y -= getSpeed();
    facing = Up;
}
