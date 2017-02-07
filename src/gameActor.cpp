#include "include/gameActor.h"
#include "include/controller.h"

GameActor::GameActor() : x_(0),
                         y_(0),
                         movement_(new Movement) {}

GameActor::GameActor(double x, double y, int vx, int vy, double speed) : x_(x),
                                                                y_(y),
                                                                movement_(new Movement(vx,vy,speed))
{
}

GameActor::~GameActor() {}

void GameActor::UpdatePosition(double timeStep) {
    x_ += timeStep * movement_->getSpeed() * movement_->getVelX();
    y_ += timeStep * movement_->getSpeed() * movement_->getVelY();

}

void GameActor::Draw() {}

void GameActor::Update() {
    UpdatePosition(Controller::getInstance()->getTimeStep());
    Draw();
}
