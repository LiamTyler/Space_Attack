#ifndef SRC_INCLUDE_INPUT_HANDLER_H_
#define SRC_INCLUDE_INPUT_HANDLER_H_

#include "include/command.h"
#include <SDL2/SDL.h>

class InputHandler {
    public:
        InputHandler();
        InputHandler(Command* left, Command* leftUp,
                     Command* right, Command* rightUp,
                     Command* up, Command* upUp,
                     Command* down, Command* downUp,
                     Command* fire, Command* fireUp);

        Command* HandleInput(SDL_Event& e);

        void BindLeft(Command* c) { left_ = c; }
        void BindRight(Command* c) { right_ = c; }
        void BindUp(Command* c) { up_ = c; }
        void BindDown(Command* c) { down_ = c; }
        void BindFire(Command* c) { fire_ = c; }
        void BindLeftUp(Command* c) { leftUp_ = c; }
        void BindRightUp(Command* c) { rightUp_ = c; }
        void BindUpUp(Command* c) { upUp_ = c; }
        void BindDownUp(Command* c) { downUp_ = c; }
        void BindFireUp(Command* c) { fireUp_ = c; }

    private:
        Command* left_;
        Command* right_;
        Command* up_;
        Command* down_;
        Command* fire_;
        Command* leftUp_;
        Command* rightUp_;
        Command* upUp_;
        Command* downUp_;
        Command* fireUp_;
};

#endif
