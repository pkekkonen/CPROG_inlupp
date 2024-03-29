#ifndef Label_h
#define Label_h

#include <string>

#include "StaticSprite.h"
#include "System.h"

class Label: public StaticSprite {
public:
    static Label* getInstance(int x, int y, int w, int h, std::string t);
    ~Label();
    void draw() const;
private:
    Label(int x, int y, int w, int h, std::string t);
    std::string text;
    SDL_Texture* texture;
};

#endif

