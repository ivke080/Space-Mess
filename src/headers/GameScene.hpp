#ifndef GAMESCENE_H_
#define GAMESCENE_H_
#include "Menu.hpp"
#include "GameOver.hpp"
#include "Scene.hpp"
#include "consts.hpp"
#include "Background.hpp"
#include "Player.hpp"
#include "Collision.hpp"
#include "Boss.hpp"
#include "Hud.hpp"
#include "BotArmy.hpp"

class GameScene : public Scene {
    private:
        bool pause; // za pauziranje igre
        Background* background;
        Player* player;
        Boss* boss;
        Hud* hud;
        BotArmy* bots;

        void initLight();

    public:
        GameScene();
        ~GameScene();
        void update();
        void render();

        void getKeyDown(unsigned char key);
        void getKeyUp(unsigned char key);
};

#endif