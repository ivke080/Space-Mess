#ifndef COLLISION_H_
#define COLLISION_H_
#include "consts.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class Collision {

    public:
        static void playerWall(Player& player, double leftEdge, double rightEdge);
        static bool entityToEntity(const Entity& e1, const Entity& e2);
        static void killableToWeapon(Killable* k, Weapon* weapon);
};

#endif