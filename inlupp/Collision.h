#ifndef Collision_h
#define Collision_h
#include <SDL2/SDL.h>

class Collision {
public:
    static bool collided(const SDL_Rect& A, const SDL_Rect& B);
};

#endif
