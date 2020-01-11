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
   // ses.setBackground("/Users/paulinakekkonen/Pictures/background.jpeg");
    
    std::vector<std::vector<int>> map(15);
    
    for(int i = 0; i < map.size(); i++)
        map[i].resize(25); //definiera dessa med namn
    
    int o = 0;
    int X = 1;
    int E = 2;
    int m = 3;
    
    map[0] = {o,o,o,o,X,o,o,o,o,o,o,X,o,o,o,o,o,o,o,o};
    map[1] = {0,1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[2] = {0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[3] = {1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[4] = {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[5] = {1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[6] = {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[7] = {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[8] = {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[9] = {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[10]= {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[11]= {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[12]= {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[13]= {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    map[14]= {0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for(int row = 0; row < map.size(); row++) {
        for(int col = 0; col < (map[row]).size(); col++) {
            if((map[row])[col] == 1)
                ses.addSprite(Wall::getInstance(col, row, 1, 1));
        }
    }
    
    Enemy* e1 = Enemy::getInstance(0, 0, 1, 1, 10, Right);
    ses.addFunction(SDLK_t, addEnemy);
    ses.addFunction(SDLK_n, addMainPlayer);
   // ses.addFunction(SDLK_s, showStatusInfo);
    StatusInfo* statInfo = StatusInfo::getInstance();
    ses.addMemberFunction(SDLK_s, std::bind(&StatusInfo::show, statInfo));

    ses.addSprite(e1);
    ses.addSprite(Ammo::getInstance(10, 10, 1, 1));
    ses.addSprite(Ammo::getInstance(12, 15, 1, 1));
    ses.run();
    return 0;
}

