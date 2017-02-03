#include "include/player.h"
#include "include/controller.h"
#include <algorithm>

Player::Player(Controller* c) : GameActor(c->getWidth() / 2, c->getHeight() / 2, 0, 0, 1, c),
                                width_(50),
                                height_(50) {

}

Player::Player(int x, int y, int w, int h, int vx, int vy, int speed, Controller* c) :
    GameActor(x, y, vx, vy, speed, c),
    width_(w),
    height_(h) {

}

void Player::UpdatePosition() {
    int sHeight = controller_->getHeight();
    int sWidth = controller_->getWidth();
    x_ = std::max(0, std::min(sWidth - width_, x_ + speed_ * vel_x_));
    y_ = std::max(0, std::min(sHeight - height_, y_ + speed_ * vel_y_));
}

void Player::Fire() {
    // No firing yet

}
