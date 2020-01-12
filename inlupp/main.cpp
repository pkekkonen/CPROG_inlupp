#include "Session.h"
#include "MainPlayer.h"
#include "Key.h"
#include "Ammo.h"
#include "StatusInfo.h"

Session ses;

void pausGame() {
    ses.paus();
}


int main(int argc, char** argv) {
   // ses.setBackground("/Users/paulinakekkonen/Pictures/Game/background.jpeg");
    
    std::vector<std::vector<int>> map(15);
    
    for(int i = 0; i < map.size(); i++)
        map[i].resize(25); //definiera dessa med namn
    
    MainPlayer* mainPlayer;
    
    const int o = 0; //empty square
    const int X = 1; //Wall
    const int E = 2; //Enemy horizontal
    const int e = 6; //Enemy moving vertically
    const int m = 3; //Main player
    const int F = 4; //Finnish
    const int k = 5; //Key
    const int A = 7; //Ammo

    map[0] = {A,A,A,m,X,o,o,o,o,o,o,E,X,E,o,o,o,o,o,o};
    map[1] = {A,X,X,X,X,X,o,X,X,o,X,X,X,o,X,o,X,o,X,o};
    map[2] = {o,o,E,X,A,X,o,e,X,o,o,o,o,E,X,o,X,X,X,o};
    map[3] = {o,X,X,X,o,X,X,o,X,X,X,o,X,X,X,o,e,X,o,e};
    map[4] = {o,E,o,X,o,o,X,o,X,o,X,X,X,o,o,e,o,X,X,o};
    map[5] = {o,X,X,X,e,X,X,o,X,o,E,o,o,o,o,o,o,k,X,o};
    map[6] = {E,o,o,X,o,X,o,o,X,o,X,o,o,o,X,X,X,X,X,o};
    map[7] = {o,o,X,X,o,X,X,o,X,e,X,o,X,X,X,e,X,o,X,o};
    map[8] = {X,o,o,o,o,o,X,o,X,o,X,X,X,o,X,o,X,e,X,o};
    map[9] = {X,X,X,X,X,o,X,o,X,o,o,o,o,o,o,o,E,o,o,o};
    map[10]= {o,o,o,o,o,E,X,o,X,o,X,X,X,X,X,X,X,X,X,X};
    map[11]= {o,X,o,X,o,o,X,o,X,o,X,o,X,o,X,o,X,o,X,F};
    map[12]= {o,X,X,X,o,X,X,o,X,X,X,e,X,e,o,e,X,e,X,o};
    map[13]= {o,X,o,X,e,o,o,o,o,o,o,o,o,o,o,o,o,o,E,o};
    map[14]= {o,o,o,o,E,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X};


    for(int row = 0; row < map.size(); row++) {
        for(int col = 0; col < (map[row]).size(); col++) {
            switch((map[row])[col]) {
                case X: ses.addSprite(Wall::getInstance(col, row, 1, 1)); break;
                case E: ses.addSprite(Enemy::getInstance(col, row, 1, 1, 5, LEFT)); break;
                case e: ses.addSprite(Enemy::getInstance(col, row, 1, 1, 10, DOWN)); break;
                case m:  mainPlayer = MainPlayer::getInstance(col, row, 1, 1, 40, 5); break;
                case F: ses.addSprite(Door::getInstance(col, row) ); break;
                case k: ses.addSprite(Key::getInstance(col, row) ); break;
                case A: ses.addSprite(Ammo::getInstance(col, row) ); break;
            }
        }
    }
    if(mainPlayer != nullptr)
        ses.addSprite(mainPlayer);
    

    StatusInfo* statInfo = StatusInfo::getInstance();
    ses.addSprite(statInfo);
    ses.addMemberFunction(SDLK_s, std::bind(&StatusInfo::show, statInfo));
    ses.addFunction(SDLK_p, pausGame);
    ses.addMemberFunction(SDLK_a, std::bind(&MainPlayer::shoot, mainPlayer));

    ses.run();
    return 0;
}

