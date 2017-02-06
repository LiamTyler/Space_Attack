#include "include/player.h"
#include "include/controller.h"
#include <algorithm>

Player::Player(Controller* c) : GameActor(c->getWidth() / 2, c->getHeight() / 2, 0, 0, 200, c),
                                width_(50),
                                height_(50),
                                weapon_(new Weapon(c)) {

}

Player::Player(double x, double y, double w, double h, int vx, int vy, double speed, Controller* c, Weapon* wp) :
    GameActor(x, y, vx, vy, speed, c),
    width_(w),
    height_(h),
    weapon_(wp) {

}

void Player::Update(double timeStep) {
    UpdatePosition(timeStep);
    Draw();
    weapon_->Update(timeStep);
}

void Player::UpdatePosition(double timeStep) {
    double sHeight = controller_->getHeight();
    double sWidth = controller_->getWidth();
    /*
    x_ = std::max(0.0, std::min(sWidth - width_, x_ + timeStep * speed_ * vel_x_));
    y_ = std::max(0.0, std::min(sHeight - height_, y_ + timeStep * speed_ * vel_y_));
    */
    x_ = std::max(0.0, std::min(sWidth - width_, x_ +
                timeStep * movement_->getSpeed() * movement_->getVelX()));
    y_ = std::max(0.0, std::min(sHeight - height_, y_ +
                timeStep * movement_->getSpeed() * movement_->getVelY()));
}

void Player::Draw() {    
    SDL_Rect fillRect = { (int) x_, (int) y_, (int) width_, (int) height_ };
    SDL_SetRenderDrawColor( controller_->getRenderer(), 255, 0, 0, 255);
    SDL_RenderFillRect( controller_->getRenderer(), &fillRect);
}

void Player::Fire() {
    weapon_->Fire(x_ + width_ / 2, y_ - 20);
}
