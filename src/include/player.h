#ifndef SRC_INCLUDE_PLAYER_H_
#define SRC_INCLUDE_PLAYER_H_

#include "include/gameActor.h"
#include "include/weapon.h"
#include "include/controller.h"

class Player : public GameActor {
    public:
        Player(Controller* c);
        Player(double x, double y, double w, double h, int vx, int vy,
               double speed, Controller* c, Weapon* wp);
        virtual void Update(double timeStep);
        virtual void UpdatePosition(double timeStep);
        virtual void Draw();
        virtual void Fire();
    private:
        Weapon* weapon_;
        double width_;
        double height_;
};

#endif
