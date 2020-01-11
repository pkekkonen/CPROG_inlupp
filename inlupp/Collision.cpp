#include "Collision.h"

bool Collision::collided(const SDL_Rect& A, const SDL_Rect& B) {
    return ((A.x+A.w > B.x && B.x+B.w > A.x && A.y+ A.h > B.y && B.y+B.h > A.y) ||
             (A.x == B.x && A.y == B.y && A.w == B.w && A.h && B.h));
}
