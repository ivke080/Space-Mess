#ifndef ENTITY_H_
#define ENTITY_H_
#include <cmath>
#include <iostream>
#include <GL/glut.h>
#include "consts.hpp"
#include "Vector3.hpp"

class Entity {

    protected:
        Vector3 position;
        Vector3 color;
        Vector3 velocity;
        double size; // Velicina objekta
        double speed;
    
    public:
        Entity(const Vector3& position, const Vector3& color, double size, double speed);
        virtual ~Entity();

        virtual void update();
        virtual void render();

        const Vector3& getPosition() const;
        const Vector3& getVelocity() const;
        const Vector3& getColor() const;
        double getSize() const;
        double getSpeed() const;

        void setPosition(const Vector3& position);
        void setVelocity(const Vector3& velocity);
        void setColor(const Vector3& color);
        void setSize(double size);
        void setSpeed(double speed);
};

#endif