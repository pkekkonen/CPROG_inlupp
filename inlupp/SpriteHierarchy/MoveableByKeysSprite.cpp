#include "MoveableByKeysSprite.h"

void MoveableByKeysSprite::keyDown(SDL_Keycode key) {
    switch(key) {
        case SDLK_LEFT: directionToMoveIn = LEFT; isMoving = true; break;
        case SDLK_RIGHT: directionToMoveIn = RIGHT; isMoving = true; break;
        case SDLK_DOWN: directionToMoveIn = DOWN; isMoving = true; break;
        case SDLK_UP: directionToMoveIn = UP; isMoving = true; break;
    }
}


bool MoveableByKeysSprite::hasThing(CollectType c) const{
    return !(bag.find(c) == bag.end());
}

void MoveableByKeysSprite::useThing(CollectType c) {
    if(--bag[c] == 0)
        bag.erase(c);
}

void MoveableByKeysSprite::addToBag(CollectType c) {
    bag[c]++;
}

int MoveableByKeysSprite::getAmountOfCollectable(CollectType type) const {
    if(hasThing(type))
        return bag.at(type);
    else
        return 0;
}


int MoveableByKeysSprite::getLifes() const {
    return lifes;
}

void MoveableByKeysSprite::move() {
    switch(directionToMoveIn) {
        case LEFT: moveLeft(); break;
        case RIGHT: moveRight(); break;
        case UP: moveUp(); break;
        case DOWN: moveDown(); break;
    }
}

void MoveableByKeysSprite::setToStartPos() {
    rect.x = startPosX;
    rect.y = startPosY;
}


