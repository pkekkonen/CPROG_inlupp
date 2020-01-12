
#ifndef Enemy_h
#define Enemy_h

#include "Session.h"
#include "Wall.h"
#include "DynamicSprite.h"

class Enemy: public DynamicSprite {
public:
    static Enemy* getInstance(int x, int y, int width, int height, int speed, Direction d);
    void draw() const;
    void tick(std::vector<Sprite*> sprites);
    
    ~Enemy();
    
private:
    Enemy(int x, int y, int w, int h, int s, Direction d);
    int counter = 0;
    SDL_Texture* texture;
    int left;
    int right;
    void moveInOtherDir();

};


#endif /* Enemy_h */
