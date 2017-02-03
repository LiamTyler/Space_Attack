#include "include/player.h"
#include "include/controller.h"
#include <algorithm>

Player::Player(Controller* c) : GameActor(c->getWidth() / 2, c->getHeight() / 2, 0, 0, 1, c),
                                width_(50),
                                height_(50),
                                weapon_(new Weapon(c)) {

}

Player::Player(int x, int y, int w, int h, int vx, int vy, int speed, Controller* c, Weapon* wp) :
    GameActor(x, y, vx, vy, speed, c),
    width_(w),
    height_(h),
    weapon_(wp) {

}

void Player::Update() {
    UpdatePosition();
    Draw();
    weapon_->Update();
}

void Player::UpdatePosition() {
    int sHeight = controller_->getHeight();
    int sWidth = controller_->getWidth();
    x_ = std::max(0, std::min(sWidth - width_, x_ + speed_ * vel_x_));
    y_ = std::max(0, std::min(sHeight - height_, y_ + speed_ * vel_y_));
}

void Player::Draw() {    
    SDL_Rect fillRect = { x_, y_, width_, height_ };
    SDL_SetRenderDrawColor( controller_->getRenderer(), 255, 0, 0, 255);
    SDL_RenderFillRect( controller_->getRenderer(), &fillRect);
}

void Player::Fire() {
    weapon_->Fire(x_ + width_ / 2, y_ - 20);
}
