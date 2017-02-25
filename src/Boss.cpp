#include "headers/Boss.hpp"

Boss::Boss(const Vector3& position, Player* player) 
    : Enemy(position, Vector3(1, 1, 1), 0.5, 0.01, 10000, player) {
    

    crashDamage = 0;
    missileNumber = 0;

    attackTypeTimer = Timer();
    attackLengthTimer = Timer();

    weapon = new Weapon(Vector3(0.498, 1, 0), 0.025, 0.1, 3, 40);
    velocity.x = speed;
    attackType = NONE;

    attackTypeTimer.start();

    //srand(time(NULL));
}
Boss::~Boss() {
    delete weapon;
}
void Boss::update() {

    Enemy::update();

    if (!dying) {
        movement();

        if (attackTypeTimer.getElapsedTime() > 2) {
            
            /* max = 3 napada, min = 1, izabere se iz enum-a jedan od napada */
            attackType = (AttackType)(rand()%(3-1+1)+1);
            attackTypeTimer.stop();
            attackLengthTimer.start();
        }

        weapon->setPosition(position);
        attack();
    } else {
        dyingSequence();
    }
        
    weapon->update();
}
void Boss::render() {
    Enemy::render();
    weapon->render();
}
void Boss::movement() {

    /* Osnovno pomeranje levo-desno */
    position.x += velocity.x;

    if (position.x >= PLAYER_WALL) {
        position.x = PLAYER_WALL - EPS;
        velocity.x *= -1;
    } else if (position.x <= - PLAYER_WALL) {
        position.x = -PLAYER_WALL + EPS;
        velocity.x *= -1;
    }
}
void Boss::attack() {

    Vector3 playerPos = player->getPosition();

    if (attackType == BURST) {
        // ispucavaju se 3 projektila, jedan za drugim, brze od ostalih
        if (missileNumber < 3) {
            weapon->setSpeed(weapon->getSpeed()+0.1); // ubrzamo ispucavanje projektila, samo za ovaj napad
            if (attackLengthTimer.getElapsedTime() > 0.08) {
                weapon->addMissile(playerPos - position);
                missileNumber++;
                attackLengthTimer.restart();
            }
            weapon->setSpeed(weapon->getSpeed()-0.1);
            return;
        }
    }
    if (attackType == LINE) {
        // ispucava 15 metaka laganezi, jedan za drugim
        if (missileNumber < 15) {
            if (attackLengthTimer.getElapsedTime() > 0.35) {
                weapon->addMissile(playerPos - position);
                missileNumber++;
                attackLengthTimer.restart();
            }
            return;
        }
    }
    if (attackType == SHOTGUN) {
        // 3 reda, po 5 projektila
        if (missileNumber < 15) {
            if (attackLengthTimer.getElapsedTime() > 0.4) {
                // u ovoj petlji pucam par projektila levo od igraca, jedan u igraca i par desno
                // da bi stvorio shotgun utisak
                for (int i = -2; i <= 2; i++) {
                    Vector3 missilePos = playerPos + Vector3(0.3*i, 0, 0);
                    weapon->addMissile(missilePos - position);
                }
                missileNumber += 5;
                attackLengthTimer.restart();
            }
            return;
        }
    }
    missileNumber = 0;
    attackTypeTimer.start();
    attackLengthTimer.stop();
}