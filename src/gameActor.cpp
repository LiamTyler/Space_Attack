#include "include/gameActor.h"

GameActor::GameActor() : x_(0),
                         y_(0),
                         movement_(new Movement),
                         controller_(nullptr) {}

GameActor::GameActor(double x, double y, int vx, int vy, double speed, Controller* c) : x_(x),
                                                                y_(y),
                                                                movement_(new Movement(vx,vy,speed)),
                                                                controller_(c) {
}

GameActor::~GameActor() {}

void GameActor::UpdatePosition(double timeStep) {
    /*
    x_ += timeStep * speed_ * vel_x_;
    y_ += timeStep * speed_ * vel_y_;
    */
    x_ += timeStep * movement_->getSpeed() * movement_->getVelX();
    y_ += timeStep * movement_->getSpeed() * movement_->getVelY();

}

void GameActor::Draw() {}

void GameActor::Update(double timeStep) {
    UpdatePosition(timeStep);
    Draw();
}
