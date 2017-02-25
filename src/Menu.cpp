#include "headers/Menu.hpp"

Menu::Menu() {
    options[0] = "Start Game";
    options[1] = "Exit";
    madeBy = "made with <3 by ivke11080 for RG16";
    selected = 0;
    background = new Background();
}
Menu::~Menu() {
    delete background;
}
void Menu::update() {
    background->update();
}
void Menu::render() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    background->render2D();

    glClear(GL_DEPTH_BUFFER_BIT); // kako zvezde ne bi isle preko teksta u meniju

    for (int i = 0; i < 2; i++) {
        if (selected == i) {
            glColor3f(1, 0, 0);
        } else {
            glColor3f(1, 1, 1);
        }
        glRasterPos2f(WIDTH/2 - (options[i].size()/2)*10, HEIGHT/2 + i*50);
        for (int j = 0; options[i][j] != '\0'; ++j) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, options[i][j]);
        }
    }
    glColor3f(0.502, 0, 0);
    glRasterPos2f(20, HEIGHT - 20);
    for (int i = 0; madeBy[i] != '\0'; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, madeBy[i]);
    }
}
void Menu::getKeyDown(unsigned char key) {
    switch (key) {
        case 's':
        case 'S':
            selected++;
            if (selected > 1)
                selected = 0;
            break;
        case 'w':
        case 'W':
            selected--;
            if (selected < 0)
                selected = 1;
            break;
        case 13:
            //Pritisnut enter
            if (selected == START) {
                delete currentScene;
                currentScene = new GameScene();
            } else if (selected == EXIT) {
                exit(1);
            }
            break;
    }
}
void Menu::getKeyUp(unsigned char key) {

}