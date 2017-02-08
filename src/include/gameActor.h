#ifndef SRC_INCLUDE_GAMEACTOR_H_
#define SRC_INCLUDE_GAMEACTOR_H_

#include "include/movement.h"

class GameActor {
    public:
        GameActor();
        GameActor(double x, double y, int vx, int vy, double speed_x, double speed_y);
        ~GameActor();
        virtual void UpdatePosition(double timeStep);
        virtual void Draw();
        virtual void Update();

        void MoveLeft() { movement_->MoveLeft(); }
        void MoveRight() { movement_->MoveRight(); }
        void MoveUp() { movement_->MoveUp(); }
        void MoveDown() { movement_->MoveDown(); }
        virtual void Fire() {}
        void StopLeft() { movement_->StopLeft(); }
        void StopRight() { movement_->StopRight(); }
        void StopUp() { movement_->StopUp(); }
        void StopDown() { movement_->StopDown(); }
        virtual void StopFire() {}

        // Getters and setters
        void setX(double x) { x_ = x; }
        void setY(double y) { y_ = y; }
        double getX() { return x_; }
        double getY() { return y_; }
        void setVelX(double x) { movement_->setVelX(x); }
        void setVelY(double y) { movement_->setVelY(y); }
        double getVelX() { return movement_->getVelX(); }
        double getVelY() { return movement_->getVelY(); }

    protected:
        double x_;
        double y_;
        Movement* movement_;
};

#endif
