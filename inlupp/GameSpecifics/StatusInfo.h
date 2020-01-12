#ifndef StatusInfo_h
#define StatusInfo_h

#include <string>

#include "System.h"
#include "Sprite.h"
#include "MainPlayer.h"


class StatusInfo: public Sprite {
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
