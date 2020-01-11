#ifndef MainPlayer_h
#define MainPlayer_h
//#include "Sprite.h"
#include "System.h"
#include "Game.h"
#include "MovingSprite.h"
#include "CollectableSprite.h"
#include <unordered_map>

//TODO: se till att inte kan kopiera eller tilldela

class MainPlayer: public MovingSprite {
public:
    static MainPlayer* getInstance(int x, int y, int width, int height, int speed, int lifes) {
        return new MainPlayer(x, y, width, height, speed, lifes);
    }
    void draw() const;
    void tick(std::vector<Sprite*> sprites);
    
    void shoot();
    
    ~MainPlayer();
    void leftKeyDown();
    void rightKeyDown();
    void downKeyDown();
    void upKeyDown();
    bool hasThing(CollectType c) const;
    void useThing(CollectType c);
    void addToBag(CollectType c);
    int getLife() const;
    int getAmountOfCollectable(CollectType type) const;
private:
    MainPlayer(int x, int y, int w, int h, int speed, int l);
    std::unordered_map<CollectType, int> bag;
    int life;
    int startPosX;
    int startPosY;
    SDL_Texture* texture;
    SDL_Surface* upSurface;
    SDL_Surface* downSurface;
    SDL_Surface* rightSurface;
    SDL_Surface* leftSurface;
    void setToStartPos();
};

#endif /* MainPlayer_h */
