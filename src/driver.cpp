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

Controller* Controller::instance_ = nullptr;

int main( int argc, char* args[] ) {
    Controller* controller = Controller::getInstance();
    if (!controller->Init(1280, 720)) {
        cerr << "Window failed to init" << endl;
        return 1;
    }

    Player* p = new Player;

    bool quit = false;
    SDL_Event e;

    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            quit = e.type == SDL_QUIT;
            Command* command = controller->HandleInput(e);
            if (command)
                command->execute(*p);
        }
        controller->ClearScreen();
        p->Update();

        controller->UpdateScreen();
    }

    return 0;
}
