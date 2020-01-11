
#include "Bullet.h"

Bullet* Bullet::getInstance(int x, int y, int speed, Direction dir) {
    return new Bullet(x/Session::SQUARE_SIZE, y/Session::SQUARE_SIZE, 1, 1, speed, dir);
    //TODO: vackrare lösning
}

void Bullet::draw() const{
    SDL_Rect r = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &r);
}

void Bullet::tick(std::vector<Sprite*> sprites) {
    counter++;
    if(counter % 5 == 0) {
        switch(direction) {
            case Up: rect.y -= getSpeed(); break;
            case Right: rect.x += getSpeed(); break;
            case Down: rect.y += getSpeed(); break;
            case Left: rect.x -= getSpeed(); break;
        }
    }
    for(Sprite* s: sprites) {
        if(Collision::collided(this->rect, s->getRect())) {
            if(Enemy* e = dynamic_cast<Enemy*>(s)) {
                ses.removeSprite(e);
                ses.removeSprite(this);
            }
            if(Wall* w = dynamic_cast<Wall*>(s))
                ses.removeSprite(this);
        }
    }
    
    if(rect.x < 0 || rect.x + rect.w > sys.getWidth() || rect.y < 0 || rect.y + rect.h > sys.getHeight())
        ses.removeSprite(this);
    
}

Bullet::~Bullet() {
    SDL_DestroyTexture(texture);
}

Bullet::Bullet(int x, int y, int w, int h, int s, Direction dir): MovingSprite(x, y, w, h, s), direction(dir) {
    texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/downBtn.jpeg");
}
