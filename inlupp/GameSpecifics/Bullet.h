#ifndef Bullet_h
#define Bullet_h
#include "DynamicSprite.h"
#include "Sprite.h"
#include "Session.h"
#include "Collision.h"
#include "Enemy.h"
#include "Wall.h"

class Bullet: public DynamicSprite {
public:
    static Bullet* getInstance(int x, int y, int speed, Direction dir);
    void draw() const;
    void tick(std::vector<Sprite*> sprites);
    
    ~Bullet();
    
private:
    Bullet(int x, int y, int w, int h, int s, Direction dir);
    int counter = 0; //TODO: Ta reda på vad den här gör
    SDL_Texture* texture;
};

#endif /* Bullet_h */
