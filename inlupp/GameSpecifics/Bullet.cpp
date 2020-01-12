
#include "Bullet.h"

Bullet* Bullet::getInstance(int x, int y, int speed, Direction dir) {
    return new Bullet(x/System::SQUARE_SIZE, y/System::SQUARE_SIZE, 1, 1, speed, dir);
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
            case UP: rect.y -= getSpeed(); break;
            case RIGHT: rect.x += getSpeed(); break;
            case DOWN: rect.y += getSpeed(); break;
            case LEFT: rect.x -= getSpeed(); break;
        }
    }
    for(Sprite* s: sprites) {
        if(Collision::collided(this->rect, s->getRect())) {
            if(Enemy* e = dynamic_cast<Enemy*>(s)) {
                ses.removeSprite(e);
                ses.removeSprite(this);
             //   delete this;

            }
            if(Wall* w = dynamic_cast<Wall*>(s)){
                ses.removeSprite(this);
             //   delete this;
            }
        }
    }
    
    if(rect.x < 0 || rect.x + rect.w > sys.getWidthInPixels() || rect.y < 0 || rect.y + rect.h > sys.getHeightInPixels())
        ses.removeSprite(this);
    
}

Bullet::~Bullet() {
    SDL_DestroyTexture(texture);
}

Bullet::Bullet(int x, int y, int w, int h, int s, Direction dir): DynamicSprite(x, y, w, h, s), direction(dir) {
    texture = IMG_LoadTexture(sys.ren, "/Users/paulinakekkonen/Pictures/Game/downBtn.jpeg");
}
