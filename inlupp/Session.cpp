#include "Session.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <iterator>

#define FPS 80

void Session::run() {
    bool quit = false;
    
    Uint32 tickInterval = 1000 / FPS;
    while(!quit) {
        Uint32 nextTick = SDL_GetTicks() + tickInterval;
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT: quit = true; break;
                case SDL_MOUSEBUTTONDOWN:
                    for(Component* c: comps)
                        c -> mouseButtonDown(event.button.x, event.button.y);
                    break;
                case SDL_MOUSEBUTTONUP:
                    for(Component* c: comps)
                        c -> mouseButtonUp(event.button.x, event.button.y);
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                            //squirrel.leftKeyDown();
                            break;
                        case SDLK_RIGHT:
                            //squirrel.rightKeyDown();
                            break;
                        case SDLK_UP:
                            //squirrel.upKeyDown();
                            break;
                        case SDLK_DOWN:
                            //squirrel.downKeyDown();
                            break;
                        default:
                            break;
                    } // keydown switch end
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                            //squirrel.leftKeyUp();
                            break;
                        case SDLK_RIGHT:
                            //squirrel.rightKeyUp();
                            break;
                        case SDLK_UP:
                            //squirrel.upKeyUp();
                            break;
                        case SDLK_DOWN:
                            //squirrel.downKeyUp();
                            break;
                        default:
                            break;
                    } // keyup switch end
                    
            } //slut på switch
            
            for(Component* c: added)
                comps.push_back(c);
            added.clear(); //måste städas bort?
            
            for(Component* c: removed) {
                for(std::vector<Component*>::iterator iter = comps.begin(); iter != comps.end();) {
                    if(*iter == c)
                        iter = comps.erase(iter);
                    else
                        iter++;
                }
            }
            removed.clear(); //måste städas bort?
            
            SDL_SetRenderDrawColor(sys.ren, 255, 255, 255, 255);
            SDL_RenderClear(sys.ren);
            for(Component* c: comps)
                c -> draw();
            SDL_RenderPresent(sys.ren);
            
        } // inre while
    } //yttre while
}

void Session::add(Component* comp) {
    added.push_back(comp);
}

void Session::remove(Component* comp) {
    removed.push_back(comp);
}
