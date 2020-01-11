#include "Session.h"

#include <SDL2/SDL.h>
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


void Session::run() {
    bool quit = false;
    int counter = 0;
    
    const int tickInterval = 1000 / FPS;
    Uint32 nextTick;
    int delay;
    
    bool left =false;
    bool right = false;
    bool up = false;
    bool down = false;
    while(!quit) {
        

        
        nextTick = SDL_GetTicks() + tickInterval;
//        const Uint8 *keys = SDL_GetKeyboardState(NULL);
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type== SDL_QUIT)
                quit = true;
            
            
            if(event.type == SDL_KEYDOWN) {
        //        switch (event.key.keysym.sym) {
          //          case SDLK_LEFT:
                        if(event.key.keysym.sym == SDLK_LEFT && !right && !up && !down) {
                            for(Sprite* s: sprites)
                                if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
                                    m->leftKeyDown();
                            left = true;
                        }
        //                break;
         //           case SDLK_RIGHT:
                        if(event.key.keysym.sym == SDLK_RIGHT && !left && !up && !down) {
                            
                            for(Sprite* s: sprites)
                                if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
                                    m->rightKeyDown();
                            right = true;
                        }
           //             break;
            //        case SDLK_UP:
                        if(event.key.keysym.sym == SDLK_UP && !right && !left && !down) {
                            for(Sprite* s: sprites)
                                if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
                                    m->upKeyDown();
                            up = true;
                        }
              //          break;
                //    case SDLK_DOWN:
                        if(event.key.keysym.sym == SDLK_DOWN && !right && !up && !left) {
                            for(Sprite* s: sprites)
                                if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
                                    m->downKeyDown();
                            down = true;
                        }
                  //      break;
                   // default:
                        if(functions.find(event.key.keysym.sym) != functions.end()) {
                            (functions.at(event.key.keysym.sym))();
                        }
                        else if(memberFunctions.find(event.key.keysym.sym) != memberFunctions.end()) {
                            (memberFunctions.at(event.key.keysym.sym))();
                            
                        }
            }
                //break;
         //       } // keydown switch end
                
                if(event.type == SDL_KEYUP) {
                    switch(event.key.keysym.sym) {
                        case SDLK_LEFT: left = false; std::cout<< std::to_string(counter++)<< std::endl; break;
                        case SDLK_RIGHT: right = false; break;
                        case SDLK_UP: up = false; break;
                        case SDLK_DOWN: down = false; break;
                    }
                }
        
//            if (keys[SDL_SCANCODE_LEFT] && keys[SDL_SCANCODE_DOWN]){
//                for(Sprite* s: sprites)
//                    if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
//                        m->leftAndDownKey();
//            }
//            else if (keys[SDL_SCANCODE_RIGHT] && keys[SDL_SCANCODE_DOWN]){
//                for(Sprite* s: sprites)
//                    if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
//                        m->rightAndDownKey();
//            }
//            else if (keys[SDL_SCANCODE_LEFT]){
//                for(Sprite* s: sprites)
//                    if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
//                        m->leftKeyDown();
//            }
//            else if (keys[SDL_SCANCODE_RIGHT]){
//                for(Sprite* s: sprites)
//                    if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
//                        m->rightKeyDown();
//            }
//            else if (keys[SDL_SCANCODE_UP]){
//                for(Sprite* s: sprites)
//                    if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
//                        m->upKeyDown();
//            }
//            else if (keys[SDL_SCANCODE_DOWN]){
//                for(Sprite* s: sprites)
//                    if(MainPlayer* m = dynamic_cast<MainPlayer*>(s))
//                        m->downKeyDown();
//            }

        } // inre while
        
        for(Sprite* s: sprites)
            s -> tick(sprites);
        
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
        
        if(background != nullptr)
            SDL_RenderCopy(sys.ren, background, NULL, NULL);
        
        for(Sprite* s: sprites)
            s -> draw();
        
        SDL_RenderPresent(sys.ren);
        
        delay = nextTick - SDL_GetTicks();
        if (delay > 0)
            SDL_Delay(delay);
    } //yttre while
    
    //TODO: ha med att rensa session typ alla sprites och så
}

