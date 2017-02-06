#ifndef SRC_INCLUDE_GAMEACTOR_H_
#define SRC_INCLUDE_GAMEACTOR_H_

#include "include/controller.h"

class GameActor {
    public:
        GameActor();
        GameActor(double x, double y, double vx, double vy, double speed, Controller* c);
        ~GameActor();
        virtual void UpdatePosition();
        virtual void Draw();
        virtual void Update();

        // Getters and setters
        inline void setX(double x) { x_ = x; }
        inline void setY(double y) { y_ = y; }
        inline void setVelX(double v) { vel_x_ = v; }
        inline void setVelY(double v) { vel_y_ = v; }
        inline void setSpeed(int speed) { speed_ = speed; }
        inline double getX() { return x_; }
        inline double getY() { return y_; }
        inline double getVelX() { return vel_x_; }
        inline double getVelY() { return vel_y_; }
        inline double getSpeed() { return speed_; }
        inline Controller* getController() { return controller_; }

    protected:
        double x_;
        double y_;
        double vel_x_;
        double vel_y_;
        double speed_;
        Controller* controller_;
};

#endif
