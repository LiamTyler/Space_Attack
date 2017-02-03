#ifndef SRC_INCLUDE_PLAYER_H_
#define SRC_INCLUDE_PLAYER_H_

#include "include/gameActor.h"
#include "include/controller.h"

class Player : public GameActor {
    public:
        Player(Controller* c);
        Player(int x, int y, int w, int h, int vx, int vy, int speed, Controller* c);
        void UpdatePosition();
        void Fire();
    private:
        int width_;
        int height_;
};

#endif
