#ifndef StatusInfo_h
#define StatusInfo_h

#include <string>

#include "System.h"
#include "MainPlayer.h"


class StatusInfo: public Sprite {
public:
    static StatusInfo* getInstance();
    void tick(std::vector<Sprite*> sprites);
    ~StatusInfo();
    void draw() const;
    void show();
private:
    StatusInfo();
    SDL_Texture* texture;
    bool isShowing;
};
#endif
