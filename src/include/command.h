#ifndef SRC_INCLUDE_COMMAND_H_
#define SRC_INCLUDE_COMMAND_H_

#include "include/gameActor.h"

class Command {
    public:
        virtual ~Command() {}
        virtual void execute(GameActor& actor) = 0;
};

#endif
