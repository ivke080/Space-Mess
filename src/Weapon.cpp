#include "headers/Weapon.hpp"
#include <iostream>
Weapon::Weapon(const Vector3& color, double size, double speed, double range, double damage) {
    this->range = range;
    this->color = color;
    this->size = size;
    this->speed = speed;
    this->damage = damage;
    missiles = vector<Missile>();
}
Weapon::~Weapon() {

}
void Weapon::checkRange() {
    int size = missiles.size();

    if (range < 0) {
        for (int i = 0; i < size; i++) {
            if (missiles[i].getPosition().z < range) {
                missiles[i] = missiles.back();
                missiles.pop_back();
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            if (missiles[i].getPosition().z > range) {
                missiles[i] = missiles.back();
                missiles.pop_back();
            }
        }
    }
}
void Weapon::update() {
    int size = missiles.size(); // da se ne bi metoda pozivala u petlji non stop
    for (int i = 0; i < size; i++) {
        missiles[i].update();
    }

    checkRange();
}
void Weapon::render() {
    int size = missiles.size();
    for (int i = 0; i < size; i++) {
        missiles[i].render();
    }
}
void Weapon::addMissile(const Vector3& direction) {
    missiles.push_back(Missile(position, color, direction, size, speed));
}
void Weapon::setPosition(const Vector3& position) {
    this->position = position;
}
void Weapon::setRange(double range) {
    this->range = range;
}
void Weapon::setSize(double size) {
    this->size = size;
}
void Weapon::setSpeed(double speed) {
    this->speed = speed;
}
void Weapon::setColor(const Vector3& color) {
    this->color = color;
}
double Weapon::getRange() const {
    return range;
}
double Weapon::getDamage() const {
    return damage;
}
double Weapon::getSpeed() const {
    return speed;
}
vector<Missile>& Weapon::getMissiles() {
    return missiles;
}