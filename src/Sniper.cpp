#include "headers/Sniper.hpp"

Sniper::Sniper(const Vector3& position, Player* player)
    : Enemy(position, Vector3(0.729, 0.333, 0.827), 0.12, 0.05, 10, player) {

    shootTimer = Timer();
    weapon = new Weapon(Vector3(0.000, 0.502, 0.502), 0.025, 0.25, 5, 80);

    shootTimer.start();
    startPosition = position.z;
    distance = 3;

    crashDamage = 0;
}
Sniper::~Sniper() {
    delete weapon;
}

void Sniper::update() {

    Enemy::update();

    if (!dying) {
        // ne puca dok ne dodje na poziciju
        if (position.z < startPosition + distance) {
            position.z += 0.1;
        } else if (shootTimer.getElapsedTime() > 1.5) {
            Vector3 playerPos = player->getPosition();
            weapon->addMissile(playerPos - position);
            shootTimer.restart();
        }

    } else {
        dyingSequence();
    }

    weapon->setPosition(position);
    weapon->update();
}
void Sniper::render() {
    Enemy::render();

    weapon->render();
}