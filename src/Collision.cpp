#include "headers/Collision.hpp"

void Collision::playerWall(Player& player, double leftEdge, double rightEdge) {
    Vector3 position = player.getPosition();

    if (position.x >= rightEdge) {
        player.setPosition(Vector3(rightEdge-EPS, position.y, position.z));
        player.moveRight(false);
        player.setVelocity(Vector3(0, 0, 0));
    } else if (position.x <= leftEdge) {
        player.setPosition(Vector3(leftEdge+EPS, position.y, position.z));
        player.moveLeft(false);
        player.setVelocity(Vector3(0, 0, 0));
    }
}
bool Collision::entityToEntity(const Entity& e1, const Entity& e2) {
    Vector3 pos1 = e1.getPosition();
    Vector3 pos2 = e2.getPosition();

    double size1 = e1.getSize() / 2;
    double size2 = e2.getSize() / 2;

    if (fabs(pos1.x - pos2.x) < size1 + size2) {
        if (fabs(pos1.y - pos2.y) < size1 + size2) {
            if (fabs(pos1.z - pos2.z) < size1 + size2) {
                return true;
            }
        }
    }
    return false;
}
void Collision::killableToWeapon(Killable* k, Weapon* weapon) {
    vector<Missile>& missiles = weapon->getMissiles();
    int size = missiles.size();

    if (!k->isDying() && !k->isDead()) { // nema kolizije ukoliko traje sekvenca umiranja
        for (int i = 0; i < size; i++) {
            if (entityToEntity(*k, missiles[i])) {
                k->setHealth(k->getHealth() - weapon->getDamage());
                k->setHit(true);
                missiles[i] = missiles.back();
                missiles.pop_back();
            }
        }
    }
}