#ifndef SRC_INCLUDE_PLAYER_H_
#define SRC_INCLUDE_PLAYER_H_

#include "include/gameActor.h"
#include "include/weapon.h"

class Player : public GameActor {
    public:
        Player();
        Player(double x, double y, double w, double h, int vx, int vy,
               double speed_x, double speed_y, Weapon* wp);
        virtual void Update();
        virtual void UpdatePosition(double timeStep);
        virtual void Draw();
        virtual void Fire();
    private:
        Weapon* weapon_;
        double width_;
        double height_;
};

#endif
