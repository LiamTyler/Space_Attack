#ifndef SRC_INCLUDE_STOP_RIGHT_COMMAND_H_
#define SRC_INCLUDE_STOP_RIGHT_COMMAND_H_

#include "include/command.h"

class StopRightCommand : public Command {
    public:
        virtual void execute(GameActor& actor) {
            actor.stopRight();
        }
};

#endif
