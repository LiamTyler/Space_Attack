#ifndef SRC_INCLUDE_INPUT_HANDLER_H_
#define SRC_INCLUDE_INPUT_HANDLER_H_

#include "include/command.h"
#include <SDL2/SDL.h>
#include <map>

class InputHandler {
    public:
        InputHandler();
        Command* HandleInput(SDL_Event& e);
    private:
        std::map<int, Command*> pressed_commands_;
        std::map<int, Command*> released_commands_;
};

#endif
