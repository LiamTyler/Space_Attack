#ifndef SRC_INCLUDE_MOVE_UP_COMMAND_H_
#define SRC_INCLUDE_MOVE_UP_COMMAND_H_

#include "include/command.h"

class MoveUpCommand : public Command {
    public:
        virtual void execute(GameActor& actor) {
            actor.moveUp();
        }
};

#endif
