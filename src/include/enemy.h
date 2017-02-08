#ifndef SRC_INCLUDE_ENEMY_H_
#define SRC_INCLUDE_ENEMY_H_

#include "include/gameActor.h"
#include "include/weapon.h"

class Enemy : public GameActor {
    public:
        Enemy();
        Enemy(double x, double y, double w, double h, int vx, int vy,
              double speed_x, double speed_y, Weapon* wp);
        ~Enemy();
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

