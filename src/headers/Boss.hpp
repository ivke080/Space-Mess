#ifndef BOSS_H_
#define BOSS_H_
#include "Enemy.hpp"
#include "Timer.hpp"
#include "consts.hpp"

enum AttackType {
    SHOTGUN = 1, BURST, LINE, NONE
};

class Boss : public Enemy {

    private:
        AttackType attackType; // tip npada
        Timer attackTypeTimer; // jer ce se tipovi napada smenjivati u vremenu
        Timer attackLengthTimer; // nakon koliko vremena se ispucava projektil u okviru odredjenog napada

        int missileNumber; // brojac koji koristim za razlicite vrste napada
        
        void movement();
        void attack();

    public:
        Boss(const Vector3& position, Player* player);
        ~Boss();

        void update();
        void render();
        
};

#endif