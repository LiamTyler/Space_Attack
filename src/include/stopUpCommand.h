#ifndef SRC_INCLUDE_STOP_UP_COMMAND_H_
#define SRC_INCLUDE_STOP_UP_COMMAND_H_

#include "include/command.h"

class StopUpCommand : public Command {
    public:
        virtual void execute(GameActor& actor) {
            actor.StopUp();
        }
};

#endif
