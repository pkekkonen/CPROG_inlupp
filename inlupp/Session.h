#ifndef Session_h
#define Session_h
#include "Component.h"
#include "Sprite.h"
#include <vector>

struct Session {
  //  Session(); //måste vi inte ha dessa?
   // ~Session();
    void addComponent(Component* comp);
    void removeComponent(Component* comp);
    void addSprite(Sprite* sprite);
    void removeSprite(Sprite* sprite);
    void run();
private:
    std::vector<Component*> comps; //TODO: måste städas bort?
    std::vector<Component*> addedComponents, removedComponents;
    std::vector<Sprite*> sprites; //TODO: måste städas bort?
    std::vector<Sprite*> addedSprites, removedSprites;

};

extern Session ses;
#endif
