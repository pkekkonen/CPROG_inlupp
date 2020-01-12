#ifndef Sprite_h
#define Sprite_h

#include <SDL2/SDL.h>
#include <vector>


class Sprite {
public:
    virtual ~Sprite() {}
    virtual void draw() const = 0;
    virtual void tick(std::vector<Sprite*> sprites) = 0;
    SDL_Rect getRect() const;
    virtual void keyDown(SDL_Keycode key) {}
protected:
    Sprite(int x, int y, int w, int h);
    SDL_Rect rect;
    const int startPosX;
    const int startPosY;
private:
    Sprite(const Sprite& other) = delete;
    const Sprite& operator=(const Sprite& other) = delete;
    
};

#endif 
