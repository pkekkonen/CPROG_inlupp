#ifndef Session_h
#define Session_h
#include "Sprite.h"
#include "MoveableByKeysSprite.h"
#include "MovingSprite.h"
#include <vector>

struct Session {
  //  Session(); //måste vi inte ha dessa?
   // ~Session();

    void addSprite(Sprite* sprite);
    void removeSprite(Sprite* sprite);
    void addMainPlayer(MoveableByKeysSprite* sprite);
    void removeMainPlayer();
    void run();
private:
    std::vector<Sprite*> sprites; //TODO: måste städas bort?
    std::vector<Sprite*> addedSprites, removedSprites;
    MoveableByKeysSprite* mainPlayer;

};

extern Session ses;
#endif
