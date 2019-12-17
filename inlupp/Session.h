#ifndef Session_h
#define Session_h
#include "Component.h"
#include <vector>

struct Session {
    Session(); //måste vi inte ha dessa?
    ~Session();
    void add(Component* comp);
    void remove(Component* comp);
    void run();
private:
    std::vector<Component*> comps; //måste städas bort?
    std::vector<Component*> added, removed;
    
};

extern Session ses;
#endif
