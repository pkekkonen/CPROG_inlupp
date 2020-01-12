#include "MainPlayer.h"

void MainPlayer::keyDown(SDL_Keycode key) {
    switch(key) {
        case SDLK_LEFT: directionToMoveIn = LEFT; isMoving = true; break;
        case SDLK_RIGHT: directionToMoveIn = RIGHT; isMoving = true; break;
        case SDLK_DOWN: directionToMoveIn = DOWN; isMoving = true; break;
        case SDLK_UP: directionToMoveIn = UP; isMoving = true; break;
    }
}


bool MainPlayer::hasThing(CollectType c) const{
    return !(bag.find(c) == bag.end());
}

void MainPlayer::useThing(CollectType c) {
    if(--bag[c] == 0)
        bag.erase(c);
}

void MainPlayer::addToBag(CollectType c) {
    bag[c]++;
}

int MainPlayer::getAmountOfCollectable(CollectType type) const {
    if(hasThing(type))
        return bag.at(type);
    else
        return 0;
}


int MainPlayer::getLife() const {
    return life;
}

void MainPlayer::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

void MainPlayer::tick(std::vector<Sprite*> sprites) {
    if(isMoving) {
        switch(directionToMoveIn) {
            case LEFT: moveLeft(); break;
            case RIGHT: moveRight(); break;
            case UP: moveUp(); break;
            case DOWN: moveDown(); break;
        }
    }
    
    isMoving = false;
    
    for(Sprite* s: sprites) {
        if(Collision::collided(getRect(), s->getRect())) {
            if(Enemy* e = dynamic_cast<Enemy*>(s)){
                if(--life == 0) {
                    ses.removeSprite(this);
                    ses.addSprite(Label::getInstance(6, 4, 8, 4, "Game over"));
                } else {
                    setToStartPos();
                }
            } else if(Wall* w = dynamic_cast<Wall*>(s)){
                setToPrevPos();
            } else if(CollectableSprite* c = dynamic_cast<CollectableSprite*>(s)) {
                addToBag(c->getCollectType());
                ses.removeSprite(c);
            } else if(Door* d = dynamic_cast<Door*>(s)) {
                if(hasThing(KEY)) {
                    useThing(KEY);
                    ses.removeSprite(this);
                    ses.addSprite(Label::getInstance(6, 4, 8, 4, "You won!"));
                }
            }
            
        }
    }
    if(!ses.isWithinWindow(&rect))
        setToPrevPos();
    
    switch(facing) {
        case UP: texture = SDL_CreateTextureFromSurface(sys.ren, upSurface); break;
        case DOWN: texture = SDL_CreateTextureFromSurface(sys.ren, downSurface); break;
        case LEFT: texture = SDL_CreateTextureFromSurface(sys.ren, leftSurface); break;
        case RIGHT: texture = SDL_CreateTextureFromSurface(sys.ren, rightSurface); break;
    }
}

void MainPlayer::shoot() {
    if(hasThing(BULLET) && life != 0 && !ses.isPaused()) {
        useThing(BULLET);
        ses.addSprite(Bullet::getInstance(rect.x, rect.y, 20, facing));
    }
}

void MainPlayer::setToStartPos() {
    rect.x = startPosX*System::SQUARE_SIZE;
    rect.y = startPosY*System::SQUARE_SIZE; //TODO: vackrare lösning
}


MainPlayer::~MainPlayer() {
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(downSurface);
    SDL_FreeSurface(upSurface);
    SDL_FreeSurface(leftSurface);
    SDL_FreeSurface(rightSurface);

    //måste vi delete unordered map?
    
}

MainPlayer::MainPlayer(int x, int y, int w, int h, int s, int l): DynamicSprite(x, y, w, h, s, DOWN), startPosX(x), startPosY(y), isMoving(false), life(l) {
    if(l < 1)
        throw std::invalid_argument("Life cannot be initilized to 0 or below.");
    downSurface = IMG_Load("/Users/paulinakekkonen/Pictures/Game/ratFacingFront.png");
    Uint32 dWhite = SDL_MapRGB(downSurface->format, 255, 255, 255);
    SDL_SetColorKey(downSurface, true, dWhite);
    upSurface = IMG_Load("/Users/paulinakekkonen/Pictures/Game/ratFacingBack.png");
    Uint32 uWhite = SDL_MapRGB(upSurface->format, 255, 255, 255);
    SDL_SetColorKey(upSurface, true, uWhite);
    leftSurface = IMG_Load("/Users/paulinakekkonen/Pictures/Game/ratFacingLeft.png");
    Uint32 lWhite = SDL_MapRGB(leftSurface
                               ->format, 255, 255, 255);
    SDL_SetColorKey(leftSurface, true, lWhite);
    rightSurface = IMG_Load("/Users/paulinakekkonen/Pictures/Game/ratFacingRight.png");
    Uint32 rWhite = SDL_MapRGB(rightSurface->format, 255, 255, 255);
    SDL_SetColorKey(rightSurface, true, rWhite);
    texture = SDL_CreateTextureFromSurface(sys.ren, downSurface);
}
