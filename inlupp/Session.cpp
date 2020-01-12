#include "Session.h"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iterator>
#include <iostream>
#include <string>
#include <iostream>
#define FPS 60

void Session::addSprite(Sprite* s) {
    addedSprites.push_back(s);
}

void Session::removeSprite(Sprite* s) {
    removedSprites.push_back(s);
}

void Session::addFunction(SDL_Keycode key, void(*f)()) {
    functions[key] = f;
}

void Session::addMemberFunction(SDL_Keycode key, std::function<void()> memFunction) {
    memberFunctions[key] = memFunction;
}

bool Session::isWithinWindow(SDL_Rect *rect) {
    return(rect->x + rect->w <= sys.getWidthInPixels() &&
           rect->x >= 0 &&
           rect->y + rect->h <= sys.getHeightInPixels() &&
           rect->y >= 0);
}

void Session::setBackground(std::string filePath) {
    background = IMG_LoadTexture(sys.ren, filePath.c_str());
}

void Session::paus() {
    isPaused = isPaused? false: true;
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
                    
                    if(!isPaused)
                        for(Sprite* s: sprites)
                            s->keyDown(event.key.keysym.sym);
                    
                    if(functions.find(event.key.keysym.sym) != functions.end())
                        (functions.at(event.key.keysym.sym))();
    
                    if(!isPaused)
                        if(memberFunctions.find(event.key.keysym.sym) != memberFunctions.end())
                        (memberFunctions.at(event.key.keysym.sym))();
                        
                    
            }
        }// inre while
        
        if(!isPaused)
            for(Sprite* s: sprites)
                s -> tick(sprites);
        
        for(Sprite* s: addedSprites)
            sprites.push_back(s);

        addedSprites.clear();
        
        for(Sprite* s: removedSprites) {
            for(std::vector<Sprite*>::iterator iter = sprites.begin(); iter != sprites.end();) {
                if(*iter == s)
                    iter = sprites.erase(iter);
                else
                    iter++;
            }
        }
        
        for(Sprite* s: removedSprites)
            delete s;
        removedSprites.clear(); //TODO: städa??
        
        SDL_SetRenderDrawColor(sys.ren, 255, 255, 255, 255);
        SDL_RenderClear(sys.ren);
        
        if(background != nullptr)
            SDL_RenderCopy(sys.ren, background, NULL, NULL);
        
        for(Sprite* s: sprites)
            s -> draw();
        
        SDL_RenderPresent(sys.ren);
        
        delay = nextTick - SDL_GetTicks();
        if (delay > 0)
            SDL_Delay(delay);
    } //yttre while
    
}

Session::~Session() {
    for(Sprite* s: sprites)
        delete s;
    SDL_DestroyTexture(background);
    std::cout << "SESSION ENDED" << std::endl;
}
