#ifndef DynamicSprite_h
#define DynamicSprite_h
#include "Sprite.h"

enum Direction {UP, DOWN, RIGHT, LEFT};

class DynamicSprite: public Sprite {
public:
    virtual ~DynamicSprite() {}
    int const getSpeed() {return speed;}

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void moveDownAndRight();
    void moveDownAndLeft();
private:
    int speed;
protected:
    int prevX;
    int prevY; //move to private TODO:
    void setToPrevPos();
    DynamicSprite(int x, int y, int w, int h, int s, Direction direction);
    Direction facing;

};
#endif /* DynamicSprite_h */
