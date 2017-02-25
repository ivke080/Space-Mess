#ifndef HUD_H_
#define HUD_H_
#include <sstream>
#include "consts.hpp"
#include "Player.hpp"
#include "Boss.hpp"

using std::ostringstream;

typedef struct {
    double x;
    double y;
    double width;
    double height;
} BossHealthBar;

class Hud {

    private:
        Player* player;
        Boss* boss;
        double bossHealth; // pocetni HP poeni, potrebni za proracun velicine HP bar-a 
        /* stringstream jer citam podatke koji su brojevi, a treba ih konvertovati u string */
        ostringstream os;
        BossHealthBar bar;

    public:
        Hud(Player* player, Boss* boss);

        void update();
        void render();
};

#endif