#ifndef PLAYER_H_
#define PLAYER_H_
#include "Killable.hpp"
#include "Timer.hpp"

#define MOVE_STEP 0.001

class Player : public Killable {

    private:
        bool left, right; // promenljive za pomeranje igraca levo desno
        bool readyToShoot; // promenljiva koja nece dozvoliti spam projektila
        Timer aliveTimer;

    public:
        Player(const Vector3& position, const Vector3& color, double size, double speed);
        ~Player();

        void update();
        void render();

        void moveRight(bool right);
        void moveLeft(bool left);
        void setReadyToShoot(bool ready);
        
        int getTimeAlive() const;
};

#endif