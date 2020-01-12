#include "MainPlayer.h"

void MainPlayer::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

void MainPlayer::tick(std::vector<Sprite*> sprites) {
    if(isMoving)
        move();
    
    isMoving = false;
    
    for(Sprite* s: sprites) {
        if(Collision::collided(getRect(), s->getRect())) {
            if(Enemy* e = dynamic_cast<Enemy*>(s)){
                if(--lifes == 0) {
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
    if(hasThing(BULLET) && lifes != 0 && !ses.isPaused()) {
        useThing(BULLET);
        ses.addSprite(Bullet::getInstance(rect.x/System::SQUARE_SIZE, rect.y/System::SQUARE_SIZE, 20, facing));
    }
}

MainPlayer::~MainPlayer() {
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(downSurface);
    SDL_FreeSurface(upSurface);
    SDL_FreeSurface(leftSurface);
    SDL_FreeSurface(rightSurface);    
}

MainPlayer::MainPlayer(int x, int y, int w, int h, int s, int l): MoveableByKeysSprite(x, y, w, h, s, DOWN, l) {
    if(l < 1)
        throw std::invalid_argument("Life cannot be initilized to 0 or below.");
    
    downSurface = IMG_Load("/Users/paulinakekkonen/Pictures/Game/characterDown.png");
    Uint32 dWhite = SDL_MapRGB(downSurface->format, 255, 255, 255);
    SDL_SetColorKey(downSurface, true, dWhite);
    upSurface = IMG_Load("/Users/paulinakekkonen/Pictures/Game/characterUp.png");
    Uint32 uWhite = SDL_MapRGB(upSurface->format, 255, 255, 255);
    SDL_SetColorKey(upSurface, true, uWhite);
    leftSurface = IMG_Load("/Users/paulinakekkonen/Pictures/Game/characterLeft.png");
    Uint32 lWhite = SDL_MapRGB(leftSurface
                               ->format, 255, 255, 255);
    SDL_SetColorKey(leftSurface, true, lWhite);
    rightSurface = IMG_Load("/Users/paulinakekkonen/Pictures/Game/characterRight.png");
    Uint32 rWhite = SDL_MapRGB(rightSurface->format, 255, 255, 255);
    SDL_SetColorKey(rightSurface, true, rWhite);
    texture = SDL_CreateTextureFromSurface(sys.ren, downSurface);
}
