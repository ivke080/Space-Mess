#include "headers/Entity.hpp"

Entity::Entity(const Vector3& position, const Vector3& color, double size, double speed) {
    this->position = position;
    this->color = color;
    this->size = size;
    this->speed = speed;
    velocity = Vector3(0, 0, 0);
}
Entity::~Entity() {

}
void Entity::update() {}
void Entity::render() {}

const Vector3& Entity::getPosition() const { return position; }
const Vector3& Entity::getVelocity() const { return velocity; }
const Vector3& Entity::getColor() const { return color; }
double Entity::getSize() const { return size; }
double Entity::getSpeed() const { return speed; }

void Entity::setPosition(const Vector3& position) {
    this->position = position;
}
void Entity::setVelocity(const Vector3& velocity) {
    this->velocity = velocity;
}
void Entity::setColor(const Vector3& color) {
    this->color = color;
}
void Entity::setSize(double size) {
    this->size = size;
}
void Entity::setSpeed(double speed) {
    this->speed = speed;
}