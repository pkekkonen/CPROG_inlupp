#include "Session.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <iterator>
#include <iostream>
#include "Collision.h"

#define FPS 80

void Session::addSprite(Sprite* s) {
    addedSprites.push_back(s);
}

void Session::removeSprite(Sprite* s) {
    removedSprites.push_back(s);
}

void Session::addMainPlayer(MoveableByKeysSprite* s) {
    mainPlayer = s; //TODO: funkar som det ska?
    //Räknas som tilldelning
}

void Session::run() {
    bool quit = false;
    
    const int tickInterval = 1000 / FPS;
    Uint32 nextTick;
    int delay;
    
    while(!quit) {
        nextTick = SDL_GetTicks() + tickInterval;
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT: quit = true; break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                            mainPlayer->leftKeyDown();
                            break;
                        case SDLK_RIGHT:
                            mainPlayer->rightKeyDown();
                            break;
                        case SDLK_UP:
                            mainPlayer->upKeyDown();
                            break;
                        case SDLK_DOWN:
                            mainPlayer->downKeyDown();
                            break;
                        default:
                            break;
                    } // keydown switch end
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                            //mainPlayer->leftKeyUp();
                            break;
                        case SDLK_RIGHT:
                            //mainPlayer->rightKeyUp();
                            break;
                        case SDLK_UP:
                            //mainPlayer->upKeyUp();
                            break;
                        case SDLK_DOWN:
                            //mainPlayer->downKeyUp();
                            break;
                        default:
                            break;
                    } // keyup switch end
                    
            } //slut på switch
        } // inre while
        delay = nextTick - SDL_GetTicks();
        if (delay > 0)
            SDL_Delay(delay);
        
        for(Sprite* s : sprites) {
            if(Collision::collided(mainPlayer->getRect(), s->getRect())) {
                removeSprite(s);
            }
        }
        
        for(Sprite* s: sprites)
            s -> tick();
        
        for(Sprite* s: addedSprites)
            sprites.push_back(s);
        addedSprites.clear(); //TODO: måste städas bort?
        
        for(Sprite* s: removedSprites) {
            for(std::vector<Sprite*>::iterator iter = sprites.begin(); iter != sprites.end();) {
                if(*iter == s)
                    iter = sprites.erase(iter);
                else
                    iter++;
            }
        }
        removedSprites.clear(); //TODO: städa??
        
        SDL_SetRenderDrawColor(sys.ren, 255, 255, 255, 255);
        SDL_RenderClear(sys.ren);
        

        for(Sprite* s: sprites)
            s -> draw();
        mainPlayer -> draw();
        SDL_RenderPresent(sys.ren);
    } //yttre while
}

