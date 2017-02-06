#ifndef SRC_INCLUDE_MOVEMENT_H_
#define SRC_INCLUDE_MOVEMENT_H_

class Movement {
    public:
        Movement();
        void MoveLeft();
        void MoveRight();
        void MoveUp();
        void MoveDown();
        void StopLeft();
        void StopRight();
        void StopUp();
        void StopDown();
        int getVelX() { return x_primary_->amount; }
        int getVelY() { return y_primary_->amount; }

    private:
        struct node {
            int amount;
            node* next;
        };
        node* x_primary_;
        node* y_primary_;
};

#endif
