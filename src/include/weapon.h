#ifndef SRC_INCLUDE_WEAPON_H_
#define SRC_INCLUDE_WEAPON_H_

#include "include/bullet.h"
#include <vector>

class Weapon {
    public:
        Weapon();
        ~Weapon();
        virtual void Fire(int x, int y);
        void Update();
    protected:
        std::vector<Bullet> bullets_;
};

#endif
