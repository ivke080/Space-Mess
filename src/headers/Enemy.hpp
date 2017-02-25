#ifndef ENEMY_H_
#define ENEMY_H_
#include "Killable.hpp"
#include "Timer.hpp"
#include "Player.hpp"

class Enemy : public Killable {

    protected:
       double crashDamage; // koliko skida HP kada se zakuca u igraca
       Timer hitTimer; // vreme koliko ce boja pogotka trajati na neprijatelju
       Vector3 hitColor; // boja kojom ce se obojiti na trenutak pogodjeni neprijatelj
       Vector3 tempColor; // trenutna boja kojom se boji (hitColor/color)
       Player* player; // Pokazivac na igraca, kako bi mogla da se koriste njegova svojstva
    
    public:
        Enemy(const Vector3& position, const Vector3& color, double size, double speed, double health, Player* player);
        
        virtual void update();
        virtual void render();

        double getCrashDamage() const;
};

#endif