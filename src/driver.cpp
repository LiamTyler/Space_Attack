#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "include/controller.h"
#include "include/player.h"
#include "include/timer.h"
#include "include/inputHandler.h"
#include "include/command.h"

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
    Timer stepTimer;
    InputHandler inputHandler;

    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT ) {
                quit = true;
            } else {
                Command* command = inputHandler.HandleInput(e);
                if (command) {
                    command->execute(*p);
                }
            }
        }
        float timeStep = stepTimer.getTicks() / 1000.f;

        window.ClearScreen();

        p->Update(timeStep);

        stepTimer.Start();

        window.UpdateScreen();
    }

    return 0;
}
