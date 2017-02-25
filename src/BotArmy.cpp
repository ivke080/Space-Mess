#include "headers/BotArmy.hpp"

BotArmy::BotArmy(Boss* boss, Player* player) {
    this->boss = boss;
    this->player = player;

    spawnTimer = Timer();
    spawnTimer.start();

    bots = vector<Enemy*>();

    botType = KAMIKAZE;
}
BotArmy::~BotArmy() {

}

void BotArmy::update() {

    if (spawnTimer.getElapsedTime() > 2.5 && !boss->isDying()) {
        spawnBot();
        spawnTimer.restart();
    }

    int size = bots.size();

    for (int i = 0; i < size; i++) {
        bots[i]->update();
    }

    for (int i = 0; i < size; i++) {

        Collision::killableToWeapon(bots[i], player->getWeapon());

        Weapon* w = bots[i]->getWeapon();
        if (w != NULL) {
            Collision::killableToWeapon(player, w);
        }

        if (!bots[i]->isDying()) {
            if (Collision::entityToEntity(*bots[i], *player)) {
                player->setHealth(player->getHealth() - bots[i]->getCrashDamage());
                bots[i]->setHealth(0);
            }
        }
    }

    for (int i = 0; i < size; i++ ) {
        if(bots[i]->isDead()) {
            delete bots[i];
            bots[i] = bots.back();
            bots.pop_back();
        }
    }
    

}
void BotArmy::render() {

    int size = bots.size();

    for (int i = 0; i < size; i++) {
        bots[i]->render();
    }
}
void BotArmy::spawnBot() {
    botType = (BotType)(rand()%2);
    int side = (rand() % 10) % 2 == 0 ? 1 : -1; // u zavisnosti od parnosti, levo ili desno
    Vector3 bossPos = boss->getPosition();
    Vector3 botPos;

    if (botType == KAMIKAZE) {
        botPos = Vector3(bossPos.x+side*0.5, bossPos.y, bossPos.z - 1);
        bots.push_back(new Kamikaze(botPos, player));
    } else if (botType == SNIPER) {
        botPos = Vector3(bossPos.x+side*0.05, bossPos.y, bossPos.z - 2);
        bots.push_back(new Sniper(botPos, player));
    } 
}