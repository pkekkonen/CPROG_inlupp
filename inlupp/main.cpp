#include <iostream>
#include "Session.h"
#include <SDL2_image/SDL_image.h>
#include "System.h"
#include <vector>
#include "StaticSprite.h"
#include "MovingSprite.h"
#include "Ammo.h" //se över dessa

Session ses;

void addEnemy() {
    Enemy* e2 = Enemy::getInstance(10, 1, 1, 1, 10, 1, 500);
    ses.addSprite(e2);
}

void addMainPlayer() {
    MainPlayer* m = MainPlayer::getInstance(5, 5, 1, 1, 40, 3);
    ses.addSprite(m);
    //TODO: modifiera lösningen så att tillämparen inte behöva binda utan bara kan skicka pointer och objektet?
    ses.addMemberFunction(SDLK_a, std::bind(&MainPlayer::shoot, m));
}

int main(int argc, char** argv) {
    Enemy* e1 = Enemy::getInstance(0, 0, 2, 2, 20, 0, 400);
    ses.addFunction(SDLK_t, addEnemy);
    ses.addFunction(SDLK_n, addMainPlayer);
    for(int i = 0; i < 6; i++)
        ses.addSprite(Wall::getInstance(8, i, 1, 1));
    for(int i = 0; i < 6; i++)
        ses.addSprite(Wall::getInstance(3+i, 6, 1, 1));
    for(int i = 0; i < 7; i++)
        ses.addSprite(Wall::getInstance(3, 6+i, 1, 1));
    ses.addSprite(e1);
    ses.addSprite(Ammo::getInstance(10, 10, 1, 1));
    ses.addSprite(Ammo::getInstance(12, 15, 1, 1));
    ses.run();
    return 0;
}

