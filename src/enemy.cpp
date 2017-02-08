#include "include/enemy.h"
#include "include/controller.h"
#include <algorithm>

Enemy::Enemy() : GameActor(Controller::getInstance()->getWidth() / 2,
                             Controller::getInstance()->getHeight() / 2, 1, 0, 200),
                             width_(50),
                             height_(50),
                             weapon_(new Weapon) {

}

Enemy::Enemy(double x, double y, double w, double h, int vx, int vy, double speed, Weapon* wp) :
    GameActor(x, y, vx, vy, speed),
    width_(w),
    height_(h),
    weapon_(wp) {

}

void Enemy::Update() {
    UpdatePosition(Controller::getInstance()->getTimeStep());
    Draw();
    weapon_->Update();
}

void Enemy::UpdatePosition(double timeStep) {
    Controller* c = Controller::getInstance();
    double sHeight = c->getHeight();
    double sWidth = c->getWidth();
    x_ = std::max(0.0, std::min(sWidth - width_, x_ +
                timeStep * movement_->getSpeed() * movement_->getVelX()));
    y_ = std::max(0.0, std::min(sHeight - height_, y_ +
                timeStep * movement_->getSpeed() * movement_->getVelY()));
}

void Enemy::Draw() {    
    Controller* c = Controller::getInstance();
    SDL_Rect fillRect = { (int) x_, (int) y_, (int) width_, (int) height_ };
    SDL_SetRenderDrawColor( c->getRenderer(), 255, 0, 0, 255);
    SDL_RenderFillRect( c->getRenderer(), &fillRect);
}

void Enemy::Fire() {
    weapon_->Fire(x_ + width_ / 2, y_ - 20);
}
