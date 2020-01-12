#include "DynamicSprite.h"

void DynamicSprite::setToPrevPos() {
        rect.x = prevX;
        rect.y = prevY;
}

void DynamicSprite::moveRight() {
    prevX = rect.x;
    prevY = rect.y;
    rect.x += getSpeed();
    facing = Right;
}

void DynamicSprite::moveLeft() {
    prevX = rect.x;
    prevY = rect.y;
    rect.x -= getSpeed();
    facing = Left;
}

void DynamicSprite::moveDown() {
    prevY = rect.y;
    prevX = rect.x;
    rect.y += getSpeed();
    facing = Down;
}
void DynamicSprite::moveUp() {
    prevY = rect.y;
    prevX = rect.x;
    rect.y -= getSpeed();
    facing = Up;
}

void DynamicSprite::moveDownAndRight() {
    prevY = rect.y;
    prevX = rect.x;
    rect.x += getSpeed();
    rect.y += getSpeed();
    facing = Right;
}

void DynamicSprite::moveDownAndLeft() {
    prevY = rect.y;
    prevX = rect.x;
    rect.x -= getSpeed();
    rect.y += getSpeed();
    facing = Left;
}
