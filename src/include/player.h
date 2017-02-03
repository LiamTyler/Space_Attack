#ifndef SRC_INCLUDE_PLAYER_H_
#define SRC_INCLUDE_PLAYER_H_

#include "include/gameActor.h"
#include "include/weapon.h"
#include "include/controller.h"

class Player : public GameActor {
    public:
        Player(Controller* c);
        Player(int x, int y, int w, int h, int vx, int vy,
               int speed, Controller* c, Weapon* wp);
        void Update();
        void UpdatePosition();
        void Draw();
        void Fire();
    private:
        Weapon* weapon_;
        int width_;
        int height_;
};

#endif
