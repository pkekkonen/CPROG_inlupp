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
    
    std::vector<std::vector<int>> gameMap(sys.getWindowHeightInSquares());
    
    for(int i = 0; i < gameMap.size(); i++)
        gameMap[i].resize(sys.getWindowWidthInSquares());
    
    MainPlayer* mainPlayer;
    
    const int o = 0; //empty square
    const int X = 1; //Wall
    const int E = 2; //Enemy moving horizontal
    const int e = 3; //Enemy moving vertical
    const int m = 4; //Main player
    const int F = 5; //The door (finish)
    const int k = 6; //Key
    const int A = 7; //Ammo

    gameMap[0] = {o,o,o,m,X,o,o,o,o,o,o,E,X,E,o,o,o,o,o,o};
    gameMap[1] = {o,X,X,X,X,X,o,X,X,o,X,X,X,o,X,o,X,o,X,o};
    gameMap[2] = {o,o,E,X,A,X,o,e,X,o,o,o,o,E,X,o,X,X,X,o};
    gameMap[3] = {o,X,X,X,o,X,X,o,X,X,X,o,X,X,X,o,e,X,o,e};
    gameMap[4] = {o,E,o,X,o,o,X,o,X,o,X,X,X,o,o,e,o,X,X,o};
    gameMap[5] = {o,X,X,X,e,X,X,o,X,o,E,o,o,o,o,o,o,o,X,o};
    gameMap[6] = {E,o,o,X,o,X,o,o,X,o,X,o,o,o,X,X,X,X,X,o};
    gameMap[7] = {o,o,X,X,o,X,X,o,X,e,X,o,X,X,X,e,X,o,X,o};
    gameMap[8] = {X,o,o,o,o,o,X,o,X,o,X,X,X,o,X,o,X,e,X,o};
    gameMap[9] = {X,X,X,X,X,o,X,o,X,o,o,o,o,o,o,o,E,o,o,o};
    gameMap[10]= {o,o,o,o,o,E,X,o,X,o,X,X,X,X,X,X,X,X,X,X};
    gameMap[11]= {o,X,o,X,o,o,X,o,X,o,X,o,X,o,X,o,X,o,X,F};
    gameMap[12]= {o,X,X,X,o,X,X,o,X,X,X,e,X,e,o,e,X,e,X,o};
    gameMap[13]= {o,X,o,X,e,o,o,o,o,o,o,o,o,o,o,o,o,o,E,o};
    gameMap[14]= {o,o,o,o,E,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X};

    ses.addSprite(Key::getInstance(17, 5));  //lägger nyckeln först i sprite vectorn så att den ritas ut före enemys så de kan "röra sig över den"
    
    for(int row = 0; row < gameMap.size(); row++)
        for(int col = 0; col < (gameMap[row]).size(); col++)
            switch((gameMap[row])[col]) {
                case X: ses.addSprite(Wall::getInstance(col, row, 1, 1)); break;
                case E: ses.addSprite(Enemy::getInstance(col, row, 1, 1, 5, LEFT)); break;
                case e: ses.addSprite(Enemy::getInstance(col, row, 1, 1, 10, DOWN)); break;
                case m:  mainPlayer = MainPlayer::getInstance(col, row, 1, 1, 40, 5); break;
                case F: ses.addSprite(Door::getInstance(col, row) ); break;
                case k: ses.addSprite(Key::getInstance(col, row) ); break;
                case A: ses.addSprite(Ammo::getInstance(col, row) ); break;
            }
    
    if(mainPlayer != nullptr)
        ses.addSprite(mainPlayer);
    
    StatusInfo* statInfo = StatusInfo::getInstance();
    ses.addSprite(statInfo);
    ses.addMemberFunction(SDLK_s, std::bind(&StatusInfo::show, statInfo));
    ses.addFunction(SDLK_p, pausGame);
    if(mainPlayer != nullptr)
        ses.addMemberFunction(SDLK_a, std::bind(&MainPlayer::shoot, mainPlayer));

    ses.run();
    return 0;
}

