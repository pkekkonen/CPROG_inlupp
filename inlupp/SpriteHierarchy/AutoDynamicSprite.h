
#ifndef AutoDynamicSprite_h
#define AutoDynamicSprite_h

#include "DynamicSprite.h"
#include "Game.h"

class AutoDynamicSprite: public DynamicSprite {
public:
    static AutoDynamicSprite* getInstance(int x, int y, int width, int height, int speed, Direction d);
    
    ~AutoDynamicSprite();
    
private:
    void moveInOtherDir();
    void collidedWithWall();

};


#endif /* AutoDynamicSprite_h */
