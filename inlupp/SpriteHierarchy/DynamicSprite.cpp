#include "DynamicSprite.h"

DynamicSprite::DynamicSprite(int x, int y, int w, int h, int s, Direction direction): Sprite(x, y, w, h), speed(s), facing(direction) {
    if(s < 1) {
        throw std::invalid_argument("Speed cannot be initilized to 0 or below.");
    }
}

void DynamicSprite::setToPrevPos() {
    rect.x = prevX;
    rect.y = prevY;
}

void DynamicSprite::moveRight() {
    prevX = rect.x;
    prevY = rect.y;
    rect.x += getSpeed();
    facing = RIGHT;
}

void DynamicSprite::moveLeft() {
    prevX = rect.x;
    prevY = rect.y;
    rect.x -= getSpeed();
    facing = LEFT;
}

void DynamicSprite::moveDown() {
    prevY = rect.y;
    prevX = rect.x;
    rect.y += getSpeed();
    facing = DOWN;
}
void DynamicSprite::moveUp() {
    prevY = rect.y;
    prevX = rect.x;
    rect.y -= getSpeed();
    facing = UP;
}

