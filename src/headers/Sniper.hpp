#ifndef SNIPER_H_
#define SNIPER_H_
#include "Enemy.hpp"
#include "Timer.hpp"
#include "Player.hpp"

class Sniper : public Enemy {

    private:
        Timer shootTimer;
        double startPosition; // pocetna pozicija od koje krece
        double distance; // koliko ce da predje pre no sto stane
    
    public:
        Sniper(const Vector3& position, Player* player);
        ~Sniper();

        void update();
        void render();

        
};

#endif