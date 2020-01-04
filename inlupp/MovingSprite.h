#ifndef MovingSprite_h
#define MovingSprite_h
#include "Sprite.h"

enum Direction {Up, Down, Right, Left};

class MovingSprite: public Sprite {
public:
    virtual ~MovingSprite() {};
    int const getSpeed() {return speed;}
    void setToPrevPos();
    Direction getFacing() const {return facing;} //inte implementera i header?
    //behövs getFacing?
    void setFacing(Direction f) {facing = f; } //ändra så ej set finns?
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
private:
    int speed;
protected:
    Direction facing;
    MovingSprite(int x, int y, int w, int h, int s): Sprite(x, y, w, h), speed(s) {};

};
#endif /* MovingSprite_h */
