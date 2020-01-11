#ifndef MovingSprite_h
#define MovingSprite_h
#include "Sprite.h"

enum Direction {Up = 1, Down, Right, Left};
//TODO: ÄNDRA TILL CAPITAL LETTERS

class MovingSprite: public Sprite {
public:
    virtual ~MovingSprite() {};
    int const getSpeed() {return speed;}
    Direction getFacing() const {return facing;} //inte implementera i header?
    //behövs getFacing?
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void moveDownAndRight();
    void moveDownAndLeft();
private:
    int speed;
    Direction facing;

protected:
    int prevX;
    int prevY; //move to private TODO:
    void setToPrevPos();
    MovingSprite(int x, int y, int w, int h, int s): Sprite(x, y, w, h), speed(s), prevX(x), prevY(y) {};
    void setFacing(Direction f) {facing = f; } //ändra så ej set finns?

};
#endif /* MovingSprite_h */
