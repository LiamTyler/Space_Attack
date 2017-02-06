#include "include/bullet.h"

Bullet::Bullet(double x, double y, double vx, double vy, double speed, Controller* c) :
    GameActor(x, y, vx, vy, speed, c),
    status_(true) {}

void Bullet::UpdatePosition() {
    x_ += speed_ * vel_x_;
    y_ += speed_ * vel_y_;

    if (x_ < 0 || controller_->getWidth() <= x_ ||
        y_ < 0 || controller_->getHeight() <= y_)
        status_ = false;
}

void Bullet::Draw() {
    SDL_Rect fillRect = { x_, y_, 10, 20 };
    SDL_SetRenderDrawColor( controller_->getRenderer(), 0, 0, 255, 255);
    SDL_RenderFillRect(controller_->getRenderer(), &fillRect);
}
