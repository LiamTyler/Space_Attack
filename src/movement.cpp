#include "include/movement.h"

Movement::Movement() : x_primary_(new node{ 0, nullptr }),
                       y_primary_(new node{ 0, nullptr }),
                       speed_(0) {}

Movement::Movement(int vx, int vy, double speed) : x_primary_(new node{ vx, nullptr }),
                                                   y_primary_(new node{ vy, nullptr }),
                                                   speed_(speed) {}

void Movement::MoveLeft() {
    if (x_primary_->amount != -1) {
        node* new_node = new node;
        new_node->amount = -1;
        if (x_primary_->next)
            delete x_primary_->next;
        new_node->next = x_primary_;
        x_primary_ = new_node;
    }
}

void Movement::MoveRight() {
    if (x_primary_->amount != 1) {
        node* new_node = new node;
        new_node->amount = 1;
        if (x_primary_->next)
            delete x_primary_->next;
        new_node->next = x_primary_;
        x_primary_ = new_node;
    }
}

void Movement::MoveUp() {
    if (y_primary_->amount != -1) {
        node* new_node = new node;
        new_node->amount = -1;
        if (y_primary_->next)
            delete y_primary_->next;
        new_node->next = y_primary_;
        y_primary_ = new_node;
    }
}

void Movement::MoveDown() {
    if (y_primary_->amount != 1) {
        node* new_node = new node;
        new_node->amount = 1;
        if (y_primary_->next)
            delete y_primary_->next;
        new_node->next = y_primary_;
        y_primary_ = new_node;
    }
}

void Movement::StopLeft() {
    if (x_primary_->amount == -1) {
        node* second = x_primary_->next;
        delete x_primary_;
        if (second) {
            x_primary_ = second;
            x_primary_->next = nullptr;
        } else {
            x_primary_ = new node;
            x_primary_->amount = 0;
            x_primary_->next = nullptr;
        }
    } else if (x_primary_->amount == 1) {
        if (x_primary_->next->amount == -1) {
            delete x_primary_->next;
            x_primary_->next = nullptr;
        }
    }
}
            
void Movement::StopRight() {
    if (x_primary_->amount == 1) {
        node* second = x_primary_->next;
        delete x_primary_;
        if (second) {
            x_primary_ = second;
            x_primary_->next = nullptr;
        } else {
            x_primary_ = new node;
            x_primary_->amount = 0;
            x_primary_->next = nullptr;
        }
    } else if (x_primary_->amount == -1) {
        if (x_primary_->next->amount == 1) {
            delete x_primary_->next;
            x_primary_->next = nullptr;
        }
    }
}

void Movement::StopUp() {
    if (y_primary_->amount == -1) {
        node* second = y_primary_->next;
        delete y_primary_;
        if (second) {
            y_primary_ = second;
            y_primary_->next = nullptr;
        } else {
            y_primary_ = new node;
            y_primary_->amount = 0;
            y_primary_->next = nullptr;
        }
    } else if (y_primary_->amount == 1) {
        if (y_primary_->next->amount == 1) {
            delete y_primary_->next;
            y_primary_->next = nullptr;
        }
    }
}

void Movement::StopDown() {
    if (y_primary_->amount == 1) {
        node* second = y_primary_->next;
        delete y_primary_;
        if (second) {
            y_primary_ = second;
            y_primary_->next = nullptr;
        } else {
            y_primary_ = new node;
            y_primary_->amount = 0;
            y_primary_->next = nullptr;
        }
    } else if (y_primary_->amount == -1) {
        if (y_primary_->next->amount == 1) {
            delete y_primary_->next;
            y_primary_->next = nullptr;
        }
    }
}

void Movement::setVelX(int v) {
    node* new_node = new node;
    new_node->amount = v;
    if (x_primary_->next)
        delete x_primary_->next;
    new_node->next = x_primary_;
    x_primary_ = new_node;
}

void Movement::setVelY(int v) {
    node* new_node = new node;
    new_node->amount = v;
    if (y_primary_->next)
        delete y_primary_->next;
    new_node->next = y_primary_;
    y_primary_ = new_node;
}
