#ifndef KAMIKAZE_H_
#define KAMIKAZE_H_
#include "Enemy.hpp"

class Kamikaze : public Enemy {

    public:
        Kamikaze(const Vector3& position, Player* player);

        void update();
        
};


#endif