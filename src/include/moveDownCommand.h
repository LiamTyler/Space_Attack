#ifndef SRC_INCLUDE_MOVE_DOWN_COMMAND_H_
#define SRC_INCLUDE_MOVE_DOWN_COMMAND_H_

#include "include/command.h"

class MoveDownCommand : public Command {
    public:
        virtual void execute(GameActor& actor) {
            actor.moveDown();
        }
};

#endif
