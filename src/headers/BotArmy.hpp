#ifndef BOTARMY_H_
#define BOTARMY_H_
#include <vector>
#include "Enemy.hpp"
#include "Timer.hpp"
#include "Kamikaze.hpp"
#include "Sniper.hpp"
#include "Player.hpp"
#include "Boss.hpp"
#include "Collision.hpp"

using std::vector;

enum BotType {
    KAMIKAZE = 0, SNIPER
};

class BotArmy {

    private:
        vector<Enemy*> bots;
        Timer spawnTimer;
        Player* player;
        Boss* boss;
        BotType botType;

        void spawnBot();
    public:
        BotArmy(Boss* boss, Player* player);
        ~BotArmy();

        void update();
        void render();
};

#endif