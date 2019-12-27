#include "Session.h"
#include "System.h"
#include <SDL2/SDL.h>
#include <iterator>
#include <iostream>
#include "Collision.h"

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
    return(rect->x + rect->w <= sys.getWidth() &&
           rect->x >= 0 &&
           rect->y + rect->h <= sys.getHeight() &&
           rect->y >= 0);
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
                            for(Sprite* s: sprites)
                                if(MoveableByKeysSprite* m = dynamic_cast<MoveableByKeysSprite*>(s))
                                    m->leftKeyDown();
                            break;
                        case SDLK_RIGHT:
                            for(Sprite* s: sprites)
                                if(MoveableByKeysSprite* m = dynamic_cast<MoveableByKeysSprite*>(s))
                                    m->rightKeyDown();
                            break;
                        case SDLK_UP:
                            for(Sprite* s: sprites)
                                if(MoveableByKeysSprite* m = dynamic_cast<MoveableByKeysSprite*>(s))
                                    m->upKeyDown();
                            break;
                        case SDLK_DOWN:
                            for(Sprite* s: sprites)
                                if(MoveableByKeysSprite* m = dynamic_cast<MoveableByKeysSprite*>(s))
                                    m->downKeyDown();
                            break;
                        default:
            //annars så är det någon annan tangent och då kan vi kolla i vår unsorted map av functions om vi har någon sådan nyckel och i så fall anropa den funktionen med den tangenten (eller egentligen så behöver vi inte ens det argumentet)
                            if(functions.find(event.key.keysym.sym) != functions.end()) {
                                (functions.at(event.key.keysym.sym))();
                            }
                            if(memberFunctions.find(event.key.keysym.sym) != memberFunctions.end()) {
                                (memberFunctions.at(event.key.keysym.sym))();
                           
                            }break;
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
        
//        for(Sprite* s : sprites) {
  //          if(Collision::collided(mainPlayer->getRect(), s->getRect())) {
    //            removeSprite(s);
      //      }
        //}
        
//        if((mainPlayer->getRect().x+mainPlayer->getRect().w) >= sys.getWidth())
//            mainPlayer->setToPrevXPos();
//        if(mainPlayer->getRect().x <= 0)
//            mainPlayer->setToPrevXPos();
//        if((mainPlayer->getRect().y+mainPlayer->getRect().h) >= sys.getHeight())
//            mainPlayer->setToPrevYPos();
//        if(mainPlayer->getRect().y <= 0)
//                mainPlayer->setToPrevYPos();
        
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
        

        for(Sprite* s: sprites)
            s -> draw();

        SDL_RenderPresent(sys.ren);
        
        delay = nextTick - SDL_GetTicks();
        if (delay > 0)
            SDL_Delay(delay);
    } //yttre while
}

