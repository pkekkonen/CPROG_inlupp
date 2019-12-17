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
        } // inre while
        
        for(Component* c: comps)
            c -> tick();
        
        for(Sprite* s: sprites)
            s -> tick();
        
        for(Component* c: addedComponents)
            comps.push_back(c);
        addedComponents.clear(); //TODO: måste städas bort?
        
        for(Sprite* s: addedSprites)
            sprites.push_back(s);
        addedSprites.clear(); //TODO: måste städas bort?
        
        for(Component* c: removedComponents) {
            for(std::vector<Component*>::iterator iter = comps.begin(); iter != comps.end();) {
                if(*iter == c)
                    iter = comps.erase(iter);
                else
                    iter++;
            }
        }
        removedComponents.clear(); //TODO: måste städas bort?
        
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
        
        for(Component* c: comps)
            c -> draw();
        for(Sprite* s: sprites)
            s -> draw();
        SDL_RenderPresent(sys.ren);
    } //yttre while
}

void Session::addComponent(Component* comp) {
    addedComponents.push_back(comp);
}

void Session::removeComponent(Component* comp) {
    removedComponents.push_back(comp);
}

void Session::addSprite(Sprite* s) {
    addedSprites.push_back(s);
}

void Session::removeSprite(Sprite* s) {
    removedSprites.push_back(s);
}
