#ifndef SRC_INCLUDE_INPUT_HANDLER_H_
#define SRC_INCLUDE_INPUT_HANDLER_H_

#include <SDL2/SDL.h>
#include "include/command.h"
#include <map>

class InputHandler {
    public:
        InputHandler();
        ~InputHandler();
        Command* HandleInput(SDL_Event& e);
    private:
        std::map<int, Command*> pressed_commands_;
        std::map<int, Command*> released_commands_;
};

#endif
