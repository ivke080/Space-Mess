#include "headers/Kamikaze.hpp"

Kamikaze::Kamikaze(const Vector3& position, Player* player) 
    :Enemy(position, Vector3(0.416, 0.353, 0.804), 0.15, 0.08, 60, player) {
    
    crashDamage = 50;
}

void Kamikaze::update() {

    Enemy::update();

    if (!dying) {
        Vector3 playerPos = player->getPosition();
        velocity = playerPos - position;

        // racuna se jedinicni vektor, kako bi konstantnom brzinom pratio igraca

        double intensity = sqrt((velocity.x*velocity.x)+(velocity.y*velocity.y) +(velocity.z*velocity.z));

        velocity.x = velocity.x/intensity;
        velocity.y = velocity.y/intensity;
        velocity.z = velocity.z/intensity;

        position += velocity * speed;
    } else {
        dyingSequence();
    }
}