#ifndef WEAPON_H_
#define WEAPON_H_
#include <vector>
#include "Missile.hpp"

using std::vector;


class Weapon {

    private:
        vector<Missile> missiles;
        double range; // domet oruzja
        double speed; // brzina metaka
        double size;  // velicina metaka
        double damage;
        Vector3 color; // boja metaka
        Vector3 position; // pozicija samog oruzja

        void checkRange(); // brise projektile van dometa
    
    public:
        Weapon(const Vector3& color, double size, double speed, double range, double damage);
        ~Weapon();

        void update();
        void render();
        void addMissile(const Vector3& position);

        void setRange(double range);
        void setSpeed(double speed);
        void setColor(const Vector3& color);
        void setSize(double size);
        void setPosition(const Vector3& position); // da bi oruzje stalno bilo gde i objekat koji ga koristi

        double getRange() const;
        double getDamage() const;
        double getSpeed() const;
        vector<Missile>& getMissiles();
};

#endif