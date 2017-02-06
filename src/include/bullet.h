#ifndef SRC_INCLUDE_BULLET_H_
#define SRC_INCLUDE_BULLET_H_

#include "include/gameActor.h"

class Bullet : public GameActor {
    public:
        Bullet(double x, double y, double vx, double vy, double speed, Controller* c);
        void UpdatePosition();
        void Draw();
        inline bool isAlive() { return status_; }
    protected:
        bool status_; /// True if alive, False if dead
};

#endif
