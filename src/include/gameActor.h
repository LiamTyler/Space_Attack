#ifndef SRC_INCLUDE_GAMEACTOR_H_
#define SRC_INCLUDE_GAMEACTOR_H_

class GameActor {
    public:
        GameActor();
        GameActor(int x, int y, int vx, int vy, int speed);
        ~GameActor();
        virtual void UpdatePosition();
        virtual void Fire() {}

        // Getters and setters
        inline void setX(int x) { x_ = x; }
        inline void setY(int y) { y_ = y; }
        inline void setVelX(int v) { vel_x_ = v; }
        inline void setVelY(int v) { vel_y_ = v; }
        inline void setSpeed(int speed) { speed_ = speed; }
        inline int getX() { return x_; }
        inline int getY() { return y_; }
        inline int getVelX() { return vel_x_; }
        inline int getVelY() { return vel_y_; }
        inline int getSpeed() { return speed_; }

    private:
        int x_;
        int y_;
        int vel_x_;
        int vel_y_;
        int speed_;
};

#endif
