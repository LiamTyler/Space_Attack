#include "include/gameActor.h"

GameActor::GameActor() : x_(0),
                         y_(0),
                         vel_x_(0),
                         vel_y_(0),
                         speed_(0) {}

GameActor::GameActor(int x, int y, int vx, int vy, int speed) : x_(x),
                                                                y_(y),
                                                                vel_x_(vx),
                                                                vel_y_(vy),
                                                                speed_(speed) {}

GameActor::~GameActor() {}

void GameActor::UpdatePosition() {
    x_ += speed_ * vel_x_;
    y_ += speed_ * vel_y_;
}
