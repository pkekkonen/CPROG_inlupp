#ifndef Bullet_h
#define Bullet_h
#include "MovingSprite.h"
#include "Sprite.h"
#include "Game.h"
#include "System.h"
#include "Enemy.h"
#include "Wall.h"

class Bullet: public MovingSprite {
public:
    static Bullet* getInstance(int x, int y, int speed, Direction dir);
    void const draw();
    void tick(std::vector<Sprite*> sprites);
    
    ~Bullet();
    
private:
    Bullet(int x, int y, int w, int h, int s, Direction dir);
    int counter = 0; //TODO: Ta reda på vad den här gör
    SDL_Texture* texture;
    Direction direction;
};

#endif /* Bullet_h */