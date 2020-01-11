#ifndef Label_h
#define Label_h

#include "StaticSprite.h"
#include "Game.h"
#include <string>
#include <SDL2_ttf/SDL_ttf.h>

class Label: public StaticSprite {
public:
    static Label* getInstance(int x, int y, int w, int h, std::string t);
    void tick(std::vector<Sprite*> sprites);
    ~Label();
    void draw() const;
private:
    Label(int x, int y, int w, int h, std::string t);
    std::string text;
    SDL_Texture* texture;
};

#endif

