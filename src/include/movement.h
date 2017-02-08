#ifndef SRC_INCLUDE_MOVEMENT_H_
#define SRC_INCLUDE_MOVEMENT_H_

struct node {
    int amount;
    node* next;
};

class Movement {
    public:
        Movement();
        Movement(int vx, int vy, double speed_x, double speed_y);
        ~Movement();
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
        int getVelX() { return x_primary_->amount * speed_x_; }
        int getVelY() { return y_primary_->amount * speed_y_; }
        void setSpeedX(double s) { speed_x_ = s; }
        void setSpeedY(double s) { speed_y_ = s; }

    private:
        node* Push(node* head, int amt);
        node* Stop(node* head, int dir);
        void ClearSecond(node* head);
        node* x_primary_;
        node* y_primary_;
        double speed_x_;
        double speed_y_;
};

#endif
