#ifndef SRC_INCLUDE_WEAPON_H_
#define SRC_INCLUDE_WEAPON_H_

#include "include/controller.h"
#include "include/bullet.h"
#include <vector>

class Weapon {
    public:
        explicit Weapon(Controller* c);
        ~Weapon();
        virtual void Fire(int x, int y);
        void Update(double timeStep);
    protected:
        std::vector<Bullet> bullets_;
        Controller* controller_;
};

#endif
