#include "headers/Killable.hpp"

Killable::Killable(const Vector3& position, const Vector3& color, double size, double speed, double health)
    : Entity(position, color, size, speed) {
    
    this->health = health;
    hit = false;
    dying = false;
    dead = false;
    weapon = NULL;
}
void Killable::update() {}
void Killable::render() {}

void Killable::setHealth(double health) {
    this->health = health;
}
void Killable::setHit(bool hit) {
    this->hit = hit;
}
void Killable::setDying(bool dying) {
    this->dying = dying;
}
void Killable::setDead(bool dead) {
    this->dead = dead;
}
void Killable::dyingSequence() {
    if (!dead) {
        position.y -= 0.05;
        if (position.y < DEATH_LINE) {
            dead = true;
        }
    }
}

double Killable::getHealth() const { return health; }
bool Killable::isHit() const { return hit; }
bool Killable::isDying() const { return dying; }
bool Killable::isDead() const { return dead; }

Weapon* Killable::getWeapon() {
    return weapon;
}