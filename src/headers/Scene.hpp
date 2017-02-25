#ifndef SCENE_H_
#define SCENE_H_
#include <iostream>

using namespace std;

class Scene {

    public:
        Scene();
        virtual ~Scene();

        virtual void update();
        virtual void render();

        virtual void getKeyDown(unsigned char key);
        virtual void getKeyUp(unsigned char key);
};

/* Ovaj pokazivac koristim za prelazak izmedju Menu i GameScene klase, pa sam ga ovde deklarisao, da bude
* globalna promenljiva */

extern Scene* currentScene;

#endif