#include "MovingSprite.h"

void MovingSprite::setToPrevPos() {
        rect.x = prevX;
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

void MovingSprite::moveDownAndRight() {
    prevY = rect.y;
    prevX = rect.x;
    rect.x += getSpeed();
    rect.y += getSpeed();
    facing = Right;
}

void MovingSprite::moveDownAndLeft() {
    prevY = rect.y;
    prevX = rect.x;
    rect.x -= getSpeed();
    rect.y += getSpeed();
    facing = Left;
}
