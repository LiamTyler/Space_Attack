#include "include/movement.h"

Movement::Movement() : x_primary_(new node{ 0, nullptr }),
                       y_primary_(new node{ 0, nullptr }),
                       speed_x_(0),
                       speed_y_(0) {}

Movement::Movement(int vx, int vy, double speed_x, double speed_y) : x_primary_(new node{ vx, nullptr }),
                                                   y_primary_(new node{ vy, nullptr }),
                                                   speed_x_(speed_x),
                                                   speed_y_(speed_y) {}

Movement::~Movement() {
    if (x_primary_->next)
        delete x_primary_->next;
    delete x_primary_;
    if (y_primary_->next)
        delete y_primary_->next;
    delete y_primary_;
}

node* Movement::Push(node* head, int amt) {
    if (head->amount != amt) {
        node* new_node = new node;
        new_node->amount = amt;
        if (head && head->next) {
            delete head->next;
            head->next = nullptr;
        }
        new_node->next = head;
        return new_node;
    } else {
        return head;
    }
}

void Movement::ClearSecond(node* head) {
    if (head->next) {
        delete head->next;
        head->next = nullptr;
    }
}

node* Movement::Stop(node* head, int dir) {
    if (head->amount == dir) {
        node* second = head->next;
        delete head;
        if (second) {
            head = second;
            head->next = nullptr;
        } else {
            head = new node { 0, nullptr};
        }
    } else if (head->amount == dir * -1) {
        if (head->next->amount == dir) {
            delete head->next;
            head->next = nullptr;
        }
    }
    return head;
}

void Movement::MoveLeft() {
    x_primary_ = Push(x_primary_, -1);
}

void Movement::MoveRight() {
    x_primary_ = Push(x_primary_, 1);
}

void Movement::MoveUp() {
    y_primary_ = Push(y_primary_, -1);
}

void Movement::MoveDown() {
    y_primary_ = Push(y_primary_, 1);
}

void Movement::StopLeft() {
    x_primary_ = Stop(x_primary_, -1);
}
            
void Movement::StopRight() {
    x_primary_ = Stop(x_primary_, 1);
}

void Movement::StopUp() {
    y_primary_ = Stop(y_primary_, -1);
}

void Movement::StopDown() {
    y_primary_ = Stop(y_primary_, 1);
}

void Movement::setVelX(int v) {
    x_primary_ = Push(x_primary_, v);
}

void Movement::setVelY(int v) {
    y_primary_ = Push(y_primary_, v);
}
