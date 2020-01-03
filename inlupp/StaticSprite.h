#ifndef StaticSprite_h
#define StaticSprite_h

class StaticSprite: public Sprite {
public:
    virtual ~StaticSprite() {}
protected:
    StaticSprite(int x, int y, int w, int h): Sprite(x, y, w, h);
};

#endif /* StaticSprite_h */
