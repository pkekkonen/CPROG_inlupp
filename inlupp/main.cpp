#include <iostream>
//#include "Session.h"
#include "Game.h"
 //se över dessa


void addEnemy() {
    Enemy* e2 = Enemy::getInstance(10, 1, 1, 1, 10, Up);
    ses.addSprite(e2);
}

void addMainPlayer() {
    MainPlayer* m = MainPlayer::getInstance(3, 2, 1, 1, 40, 3);
    ses.addSprite(m);
    //TODO: modifiera lösningen så att tillämparen inte behöva binda utan bara kan skicka pointer och objektet?
    ses.addMemberFunction(SDLK_a, std::bind(&MainPlayer::shoot, m));
}


int main(int argc, char** argv) {
   // ses.setBackground("/Users/paulinakekkonen/Pictures/Game/background.jpeg");
    
    std::vector<std::vector<int>> map(15);
    
    for(int i = 0; i < map.size(); i++)
        map[i].resize(25); //definiera dessa med namn
    
    MainPlayer* mainP;
    
    const int o = 0; //empty square
    const int X = 1; //Wall
    const int E = 2; //Enemy
    const int m = 3; //Main player
    const int F = 4; //Finnish
    const int k = 5; //Finnish

    map[0] = {o,o,o,m,o,o,o,o,o,o,o,X,o,o,o,o,o,o,o,o};
    map[1] = {o,X,X,X,X,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o};
    map[2] = {o,o,E,X,o,o,o,o,o,o,o,X,X,X,X,X,o,o,o,o};
    map[3] = {o,X,X,X,o,o,o,o,o,o,o,X,X,X,X,X,o,o,o,o};
    map[4] = {o,E,o,X,o,o,o,o,o,o,o,X,X,X,X,X,o,o,o,o};
    map[5] = {o,X,X,X,o,o,o,o,o,o,o,X,X,X,X,X,o,o,o,o};
    map[6] = {E,o,o,X,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o};
    map[7] = {o,o,o,o,o,o,o,o,o,o,o,o,k,o,o,o,o,o,o,o};
    map[8] = {o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o};
    map[9] = {o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o};
    map[10]= {o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o};
    map[11]= {o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,F,o,o};
    map[12]= {o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o};
    map[13]= {o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o};
    map[14]= {X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X};


    for(int row = 0; row < map.size(); row++) {
        for(int col = 0; col < (map[row]).size(); col++) {
            switch((map[row])[col]) {
                case X: ses.addSprite(Wall::getInstance(col, row, 1, 1)); break;
                case E: ses.addSprite(Enemy::getInstance(col, row, 1, 1, 5, Left)); break;
                case m:  mainP = MainPlayer::getInstance(col, row, 1, 1, 40, 3); break;
                case F: ses.addSprite(Door::getInstance(col, row) ); break;
                case k: ses.addSprite(Key::getInstance(col, row) ); break;
            }
        }
    }
    if(mainP != nullptr)
        ses.addSprite(mainP);
    
//    Enemy* e1 = Enemy::getInstance(0, 0, 1, 1, 10, Right);
//    ses.addFunction(SDLK_t, addEnemy);
//    ses.addFunction(SDLK_n, addMainPlayer);
   // ses.addFunction(SDLK_s, showStatusInfo);
    StatusInfo* statInfo = StatusInfo::getInstance();
    ses.addMemberFunction(SDLK_s, std::bind(&StatusInfo::show, statInfo));
    ses.addMemberFunction(SDLK_a, std::bind(&MainPlayer::shoot, mainP));


//    ses.addSprite(e1);
    ses.addSprite(Ammo::getInstance(10, 10));
    ses.addSprite(Ammo::getInstance(12, 10));
    ses.run();
    return 0;
}

