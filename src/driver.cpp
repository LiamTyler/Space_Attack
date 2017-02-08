#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "include/controller.h"
#include "include/player.h"
#include "include/enemy.h"
#include "include/command.h"

using namespace std;

Controller* Controller::instance_ = nullptr;

int main( int argc, char* args[] ) {
    Controller* controller = Controller::getInstance();
    if (!controller->Init(1280, 720)) {
        cerr << "Window failed to init" << endl;
        return 1;
    }

    Player* player = new Player;
    Enemy* enemy = new Enemy;

    bool quit = false;
    SDL_Event e;

    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            quit = e.type == SDL_QUIT;
            Command* command = controller->HandleInput(e);
            if (command)
                command->execute(*player);
        }
        controller->ClearScreen();
        enemy->Update();
        player->Update();

        controller->UpdateScreen();
    }

    delete player;
    delete enemy;
    delete controller;

    return 0;
}
