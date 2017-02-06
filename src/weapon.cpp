#include "include/weapon.h"

Weapon::Weapon(Controller* c) : bullets_(),
                                controller_(c) {}

Weapon::~Weapon() {}


void Weapon::Fire(int x, int y) {
    Bullet b = Bullet(x, y, 0, -1, 150, controller_);
    b.Draw();
    bullets_.push_back(b);
}

void Weapon::Update(double timeStep) {
    std::vector<Bullet> new_bullets;
    for (int i = 0; i < bullets_.size(); i++) {
       bullets_[i].UpdatePosition(timeStep);
       if (bullets_[i].isAlive()) {
           new_bullets.push_back(bullets_[i]);
           bullets_[i].Draw();
       }
    }
    bullets_ = new_bullets;
}
