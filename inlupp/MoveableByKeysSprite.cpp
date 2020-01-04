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

