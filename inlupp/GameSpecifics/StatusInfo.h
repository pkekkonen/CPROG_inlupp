
#ifndef StatusInfo_h
#define StatusInfo_h
#include "StaticSprite.h"
#include "Game.h"
#include <SDL2_ttf/SDL_ttf.h>

class StatusInfo: public StaticSprite {
public:
    static StatusInfo* getInstance();
    void tick(std::vector<Sprite*> sprites);
    ~StatusInfo();
    void draw() const;
    void show(); //ska vara const
private:
    StatusInfo();
    SDL_Texture* texture;
    bool isShowing;
};
#endif
