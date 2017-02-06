#ifndef SRC_INCLUDE_MOVE_RIGHT_COMMAND_H_
#define SRC_INCLUDE_MOVE_RIGHT_COMMAND_H_

#include "include/command.h"

class MoveRightCommand: public Command {
    public:
        virtual void execute(GameActor& actor) {
            actor.moveRight();
        }
};

#endif
