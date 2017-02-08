#include "include/inputHandler.h"
#include "include/moveLeftCommand.h"
#include "include/moveRightCommand.h"
#include "include/moveUpCommand.h"
#include "include/moveDownCommand.h"
#include "include/fireCommand.h"
#include "include/stopLeftCommand.h"
#include "include/stopRightCommand.h"
#include "include/stopUpCommand.h"
#include "include/stopDownCommand.h"
#include "include/stopFireCommand.h"
#include <SDL2/SDL.h>

InputHandler::InputHandler() {
    pressed_commands_[SDLK_UP] = new MoveUpCommand();
    pressed_commands_[SDLK_DOWN] = new MoveDownCommand();
    pressed_commands_[SDLK_LEFT] = new MoveLeftCommand();
    pressed_commands_[SDLK_RIGHT] = new MoveRightCommand();
    pressed_commands_[SDLK_SPACE] = new FireCommand();

    released_commands_[SDLK_UP] = new StopUpCommand();
    released_commands_[SDLK_DOWN] = new StopDownCommand();
    released_commands_[SDLK_LEFT] = new StopLeftCommand();
    released_commands_[SDLK_RIGHT] = new StopRightCommand();
    released_commands_[SDLK_SPACE] = new StopFireCommand();
}

InputHandler::~InputHandler() {
    std::map<int, Command*>::iterator it;
    for (it = pressed_commands_.begin(); it != pressed_commands_.end(); it++)
        delete it->second;
    for (it = released_commands_.begin(); it != released_commands_.end(); it++)
        delete it->second;
}

Command* InputHandler::HandleInput(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        return pressed_commands_[e.key.keysym.sym];
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        return released_commands_[e.key.keysym.sym];
    }
    return nullptr;
}
