#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "include/controller.h"
#include "include/player.h"

using namespace std;

int main( int argc, char* args[] ) {
    Controller window(1280, 720);
    if (!window.Init()) {
        cerr << "Window failed to init" << endl;
        return 1;
    }
    SDL_Renderer* gRenderer = window.getRenderer();

    Player* p = new Player(&window);

    bool quit = false;
    SDL_Event e;

    while( !quit ) {
        p->UpdatePosition();
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
            {
                quit = true;
            } else if (e.type == SDL_KEYDOWN ) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        p->setVelY(-1);
                        break;
                    case SDLK_DOWN:
                        p->setVelY(1);
                        break;
                    case SDLK_LEFT:
                        p->setVelX(-1);
                        break;
                    case SDLK_RIGHT:
                        p->setVelX(1);
                        break;
                }
            } else if (e.type == SDL_KEYUP ) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                    case SDLK_DOWN:
                        p->setVelY(0);
                        break;
                    case SDLK_LEFT:
                    case SDLK_RIGHT:
                        p->setVelX(0);
                        break;
                }
            }

        }

        window.Clear();

        SDL_Rect fillRect = { p->getX(), p->getY(), 50, 50 };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );		
        SDL_RenderFillRect( gRenderer, &fillRect );

        window.UpdateScreen();
    }

    return 0;
}
