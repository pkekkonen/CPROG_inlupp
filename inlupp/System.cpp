//
//  System.cpp
//  inlupp
//
//  Created by Paulina Kekkonen on 2019-12-06.
//  Copyright © 2019 Paulina Kekkonen. All rights reserved.
//

#include "System.h"

System::System() {
    win = SDL_CreateWindow("Game", 10, 10, 700, 500, 0); //TODO: ta reda på vad siffrorna innebär
    ren = SDL_CreateRenderer(win, -1, 0);
}

System::~System() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
}

System sys;
