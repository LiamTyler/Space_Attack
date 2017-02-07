#include "include/weapon.h"
#include "include/controller.h"

Weapon::Weapon() : bullets_() {}

Weapon::~Weapon() {}

void Weapon::Fire(int x, int y) {
    Bullet b = Bullet(x, y, 0, -1, 150);
    b.Draw();
    bullets_.push_back(b);
}

void Weapon::Update() {
    std::vector<Bullet> new_bullets;
    for (int i = 0; i < bullets_.size(); i++) {
       bullets_[i].UpdatePosition(Controller::getInstance()->getTimeStep());

       if (bullets_[i].isAlive()) {
           new_bullets.push_back(bullets_[i]);
           bullets_[i].Draw();
       }
    }
    bullets_ = new_bullets;
}
