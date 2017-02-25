#ifndef GAMEOVER_H_
#define GAMEOVER_H_
#include "Scene.hpp"
#include "Menu.hpp"
#include "consts.hpp"
#include "Timer.hpp"
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

class GameOver : public Scene {

    private:
        string text;
        string alive;
        Timer msgTimer;
        ostringstream os;
    public:
        GameOver(int seconds);

        void render();
        void update();


};

#endif