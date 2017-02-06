#ifndef SRC_INCLUDE_STOP_FIRE_COMMAND_H_
#define SRC_INCLUDE_STOP_FIRE_COMMAND_H_

#include "include/command.h"

class StopFireCommand : public Command {
    public:
        virtual void execute(GameActor& actor) {
            // actor.Fire();
        }
};

#endif
