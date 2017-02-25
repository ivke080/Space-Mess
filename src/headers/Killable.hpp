#ifndef KILLABLE_H_
#define KILLABLE_H_
#include "Entity.hpp"
#include "Weapon.hpp"

class Killable : public Entity {

    protected:
        double health;
        bool hit; // indikator da li je pogodjen
        bool dying; // da li se izvrsava metoda umiranja
        bool dead; // da li je mrtav
        Weapon* weapon;

        void dyingSequence();

    public:
        Killable(const Vector3& position, const Vector3& color, double size, double speed, double health);

        virtual void update();
        virtual void render();

        void setHealth(double health);
        void setHit(bool hit);
        void setDying(bool dying);
        void setDead(bool dead);

        double getHealth() const;
        bool isHit() const;
        bool isDying() const;
        bool isDead() const;

        Weapon* getWeapon();
};

#endif