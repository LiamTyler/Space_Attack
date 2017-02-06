#ifndef SRC_INCLUDE_MOVEMENT_H_
#define SRC_INCLUDE_MOVEMENT_H_

class Movement {
    public:
        Movement();
        Movement(int vx, int vy, double speed);
        void MoveLeft();
        void MoveRight();
        void MoveUp();
        void MoveDown();
        void StopLeft();
        void StopRight();
        void StopUp();
        void StopDown();
        void setVelX(int v);
        void setVelY(int v);
        int getVelX() { return x_primary_->amount; }
        int getVelY() { return y_primary_->amount; }
        void setSpeed(double s) { speed_ = s; }
        double getSpeed() { return speed_; }

    private:
        struct node {
            int amount;
            node* next;
        };
        node* x_primary_;
        node* y_primary_;
        double speed_;
};

#endif
