#ifndef SRC_INCLUDE_MOVE_LEFT_COMMAND_H_
#define SRC_INCLUDE_MOVE_LEFT_COMMAND_H_

#include "include/command.h"

class MoveLeftCommand : public Command {
    public:
        virtual void execute(GameActor& actor) {
            actor.MoveLeft();
        }
};

#endif
