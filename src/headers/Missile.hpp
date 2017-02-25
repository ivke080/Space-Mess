#ifndef MISSILE_H_
#define MISSILE_H_
#include "Entity.hpp"

class Missile : public Entity {

    public:
        Missile(const Vector3& position, const Vector3& color, const Vector3& direction, double size, double speed);

        void update();
        void render();
};

#endif