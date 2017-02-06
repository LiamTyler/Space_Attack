#ifndef SRC_INCLUDE_STOP_LEFT_COMMAND_H_
#define SRC_INCLUDE_STOP_LEFT_COMMAND_H_

#include "include/command.h"

class StopLeftCommand : public Command {
    public:
        virtual void execute(GameActor& actor) {
            actor.stopLeft();
        }
};

#endif
