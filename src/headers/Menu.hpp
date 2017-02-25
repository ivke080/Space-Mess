#ifndef MENU_H_
#define MENU_H_
#include "consts.hpp"
#include "Scene.hpp"
#include "GameScene.hpp"
#include <string>
#include "Background.hpp"

#define START 0
#define EXIT 1

class Menu : public Scene {

    private:
        string options[2];
        string madeBy;
        int selected;
        Background *background;

    public:
        Menu();
        ~Menu();

        void update();
        void render();

        void getKeyDown(unsigned char key);
        void getKeyUp(unsigned char key);
};


#endif