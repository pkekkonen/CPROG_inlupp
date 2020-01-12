#ifndef MainPlayer_h
#define MainPlayer_h

#include <unordered_map>

#include "Session.h"
#include "Enemy.h"
#include "Wall.h"
#include "Label.h"
#include "Door.h"
#include "Bullet.h"
#include "CollectableSprite.h"
#include "MoveableByKeysSprite.h"


class MainPlayer: public MoveableByKeysSprite {
public:
    static MainPlayer* getInstance(int x, int y, int width, int height, int speed, int lifes) {
        return new MainPlayer(x, y, width, height, speed, lifes);
    }
    void draw() const;
    void tick(std::vector<Sprite*> sprites);
    ~MainPlayer();
    void shoot();
private:
    MainPlayer(int x, int y, int w, int h, int speed, int l);
    SDL_Texture* texture;
    SDL_Surface* upSurface;
    SDL_Surface* downSurface;
    SDL_Surface* rightSurface;
    SDL_Surface* leftSurface;
};

#endif
