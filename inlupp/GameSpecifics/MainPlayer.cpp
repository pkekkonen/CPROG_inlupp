#include "MainPlayer.h"

void MainPlayer::leftKeyDown() {
    moveLeft();
}

void MainPlayer::rightKeyDown() {
    moveRight();
}

void MainPlayer::downKeyDown() {
    moveDown();
}

void MainPlayer::upKeyDown() {
    moveUp();
}

//returns false if thing is not present
bool MainPlayer::hasThing(CollectType c) {
    if(bag.find(c) == bag.end())
        return false;
    if(--bag[c] == 0)
        bag.erase(c);
    return true;
}

void MainPlayer::addToBag(CollectType c) {
    bag[c]++;
}



void const MainPlayer::draw() {
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

void MainPlayer::tick(std::vector<Sprite*> sprites) {
    for(Sprite* s: sprites) {
        if(Collision::collided(this->getRect(), s->getRect())) {
            if(Enemy* e = dynamic_cast<Enemy*>(s)){
                if(--life == 0) {
                    //vad som ska hända om man dör helt
                    ses.removeSprite(this);
                } else {
                    setToStartPos();
                }
            } else if(Wall* w = dynamic_cast<Wall*>(s)){
                this -> setToPrevPos();
            } else if(CollectableSprite* c = dynamic_cast<CollectableSprite*>(s)) {
                this -> addToBag(c->getCollectType());
            }
            
        }
    }
    if(!ses.isWithinWindow(&rect))
        this->setToPrevPos();
    
    switch(getFacing()) {
        case Up: texture = SDL_CreateTextureFromSurface(sys.ren, upSurface); break;
        case Down: texture = SDL_CreateTextureFromSurface(sys.ren, downSurface); break;
        case Left: texture = SDL_CreateTextureFromSurface(sys.ren, leftSurface); break;
        case Right: texture = SDL_CreateTextureFromSurface(sys.ren, rightSurface); break;
    }
}

void MainPlayer::shoot() {
    if(this->hasThing(BULLET))
        ses.addSprite(Bullet::getInstance(rect.x, rect.y, 6, getFacing()));
}

void MainPlayer::setToStartPos() {
    rect.x = startPosX*Session::SQUARE_SIZE;
    rect.y = startPosY*Session::SQUARE_SIZE; //TODO: vackrare lösning
}


MainPlayer::~MainPlayer() {
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(downSurface);
    SDL_FreeSurface(upSurface);
    SDL_FreeSurface(leftSurface);
    SDL_FreeSurface(rightSurface);
    
}

MainPlayer::MainPlayer(int x, int y, int w, int h, int s, int l): MovingSprite(x, y, w, h, s), life(l), startPosX(x), startPosY(y) {
    downSurface = IMG_Load("/Users/paulinakekkonen/Pictures/ratFacingFront.png");
    Uint32 dWhite = SDL_MapRGB(downSurface->format, 255, 255, 255);
    SDL_SetColorKey(downSurface, true, dWhite);
    upSurface = IMG_Load("/Users/paulinakekkonen/Pictures/ratFacingBack.png");
    Uint32 uWhite = SDL_MapRGB(upSurface->format, 255, 255, 255);
    SDL_SetColorKey(upSurface, true, uWhite);
    leftSurface = IMG_Load("/Users/paulinakekkonen/Pictures/ratFacingLeft.png");
    Uint32 lWhite = SDL_MapRGB(leftSurface
                               ->format, 255, 255, 255);
    SDL_SetColorKey(leftSurface, true, lWhite);
    rightSurface = IMG_Load("/Users/paulinakekkonen/Pictures/ratFacingRight.png");
    Uint32 rWhite = SDL_MapRGB(rightSurface->format, 255, 255, 255);
    SDL_SetColorKey(rightSurface, true, rWhite);
    texture = SDL_CreateTextureFromSurface(sys.ren, downSurface);
}
