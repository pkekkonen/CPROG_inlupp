#ifndef MovingSprite_h
#define MovingSprite_h

class MovingSprite: public Sprite {
public:
    virtual ~MovingSprite() {};
    int const getSpeed() {return speed;}
private:
    int speed;
protected:
    MovingSprite(int x, int y, int w, int h, int s): Sprite(x, y, w, h), speed(s) {};

};
#endif /* MovingSprite_h */
