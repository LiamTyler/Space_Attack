#ifndef SRC_INCLUDE_PLAYER_H_
#define SRC_INCLUDE_PLAYER_H_

#include "include/gameActor.h"

class Player : public GameActor {
    public:
        Player();
        Player(int x, int y, int vx, int vy, int speed);
        void Fire();
};

#endif
