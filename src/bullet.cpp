#include "include/bullet.h"
#include "include/controller.h"
#include <SDL2/SDL.h>

Bullet::Bullet(double x, double y, double vx, double vy, double speed) :
    GameActor(x, y, vx, vy, speed),
    status_(true) {}

void Bullet::UpdatePosition(double timeStep) {
    x_ += timeStep * movement_->getSpeed() * movement_->getVelX();
    y_ += timeStep * movement_->getSpeed() * movement_->getVelY();

    Controller* c = Controller::getInstance();
    if (x_ < 0 || c->getWidth() <= x_ || y_ < 0 || c->getHeight() <= y_)
        status_ = false;
}

void Bullet::Draw() {
    Controller* c = Controller::getInstance();
    SDL_Rect fillRect = { (int) x_, (int) y_, 10, 20 };
    SDL_SetRenderDrawColor( c->getRenderer(), 0, 0, 255, 255);
    SDL_RenderFillRect(c->getRenderer(), &fillRect);
}
