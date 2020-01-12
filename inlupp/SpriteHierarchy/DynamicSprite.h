#ifndef DynamicSprite_h
#define DynamicSprite_h
#include "Sprite.h"

enum Direction {UP, DOWN, RIGHT, LEFT};

class DynamicSprite: public Sprite {
public:
    virtual ~DynamicSprite() {}
    int const getSpeed() {return speed;}
private:
    int speed;
    int prevX;
    int prevY;
protected:
    void setToPrevPos();
    DynamicSprite(int x, int y, int w, int h, int s, Direction direction);
    Direction facing;
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

};
#endif 
