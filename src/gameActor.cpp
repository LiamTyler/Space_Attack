#include "include/gameActor.h"

GameActor::GameActor() : x_(0),
                         y_(0),
                         vel_x_(0),
                         vel_y_(0),
                         speed_(0) {}

GameActor::GameActor(double x, double y, double vx, double vy, double speed, Controller* c) : x_(x),
                                                                y_(y),
                                                                vel_x_(vx),
                                                                vel_y_(vy),
                                                                speed_(speed),
                                                                controller_(c) {
}

GameActor::~GameActor() {}

void GameActor::UpdatePosition(double timeStep) {
    /*
    x_ += timeStep * speed_ * vel_x_;
    y_ += timeStep * speed_ * vel_y_;
    */
    x_ += timeStep * speed_ * movement_.getVelX();
    y_ += timeStep * speed_ * movement_.getVelY();

}

void GameActor::Draw() {}

void GameActor::Update(double timeStep) {
    UpdatePosition(timeStep);
    Draw();
}
