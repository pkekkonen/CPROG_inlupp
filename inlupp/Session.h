#ifndef Session_h
#define Session_h
#include "Sprite.h"
#include "MoveableByKeysSprite.h"
#include "MovingSprite.h"
#include <vector>
#include <unordered_map>
#include <utility>
#include "MemberFunctionPair.h"

//TODO: göra till klass?
struct Session {
   // ~Session(); måste städa bort vector

    void addSprite(Sprite* sprite);
    void removeSprite(Sprite* sprite);
    void run();
    void addFunction(SDL_Keycode key, void(*f)() );
    void addMemberFunction(SDL_Keycode key, std::function<void()> memFunction);
    bool isWithinWindow(SDL_Rect* rect);
    static const int SQUARE_SIZE = 40;
private:
    std::vector<Sprite*> sprites; //TODO: måste städas bort?
    std::vector<Sprite*> addedSprites, removedSprites;
    std::unordered_map<SDL_Keycode, void (*)()> functions; //ska funktionerna anropas med den key som tryckts ner? Kaka på kaka?
    std::unordered_map<SDL_Keycode,std::function<void()>> memberFunctions;
};

extern Session ses;
#endif
