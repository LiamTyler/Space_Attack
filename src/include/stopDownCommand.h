#ifndef SRC_INCLUDE_STOP_DOWN_COMMAND_H_
#define SRC_INCLUDE_STOP_DOWN_COMMAND_H_

#include "include/command.h"

class StopDownCommand : public Command {
    public:
        virtual void execute(GameActor& actor) {
            actor.stopDown();
        }
};

#endif
