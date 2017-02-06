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

InputHandler::InputHandler() : left_(new MoveLeftCommand),
                               leftUp_(new StopLeftCommand),
                               right_(new MoveRightCommand),
                               rightUp_(new StopRightCommand),
                               up_(new MoveUpCommand),
                               upUp_(new StopUpCommand),
                               down_(new MoveDownCommand),
                               downUp_(new StopDownCommand),
                               fire_(new FireCommand),
                               fireUp_(new StopFireCommand) {}

InputHandler::InputHandler(Command* left, Command* leftUp,
                           Command* right, Command* rightUp,
                           Command* up, Command* upUp,
                           Command* down, Command* downUp,
                           Command* fire, Command* fireUp) : 
    left_(left), leftUp_(leftUp),
    right_(right), rightUp_(rightUp),
    up_(up), upUp_(upUp),
    down_(down), downUp_(downUp),
    fire_(fire), fireUp_(fireUp) {}

Command* InputHandler::HandleInput(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                return up_;
            case SDLK_DOWN:
                return down_;
            case SDLK_LEFT:
                return left_;
            case SDLK_RIGHT:
                return right_;
            case SDLK_SPACE:
                return fire_;
            default:
                return nullptr;
        }
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                return upUp_;
            case SDLK_DOWN:
                return downUp_;
            case SDLK_LEFT:
                return leftUp_;
            case SDLK_RIGHT:
                return rightUp_;
            default:
                return nullptr;
        }
    }
    return nullptr;
}
