#include "Wall.h"

Wall* Wall::getInstance(int x, int y, int w, int h) {
    return new Wall(x, y, w, h);
}

void Wall::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

Wall::~Wall() {
    SDL_DestroyTexture(texture);
}

void Wall::tick(std::vector<Sprite*> sprites) {
    for(Sprite* s : sprites) {
        if(Collision::collided(this->rect, s-> getRect())) {
        }
    }
}

Wall::Wall(int x, int y, int w, int h): StaticSprite(x,y,w,h) {
    texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/squareBrick.jpg");
}
