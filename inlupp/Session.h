#ifndef Session_h
#define Session_h

#include <iterator>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>

#include "Sprite.h"
#include "System.h"
#include "Collision.h"


class Session {
public:
    ~Session();
    void addSprite(Sprite* sprite);
    void removeSprite(Sprite* sprite);
    void run();
    void addFunction(SDL_Keycode key, void(*f)() );
    void addMemberFunction(SDL_Keycode key, std::function<void()> memFunction);
    bool isWithinWindow(SDL_Rect* rect);
    void setBackground(std::string filePath);
    void paus();
    bool isPaused() const;
private:
    std::vector<Sprite*> sprites;
    std::vector<Sprite*> addedSprites, removedSprites;
    std::unordered_map<SDL_Keycode, void (*)()> functions;
    std::unordered_map<SDL_Keycode,std::function<void()>> memberFunctions;
    SDL_Texture* background;
    bool paused = false;
};

extern Session ses;
#endif
