#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include "headers/consts.hpp"
#include "headers/Menu.hpp"

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;
const int TIMER_INTERVAL = 20;
const double PLAYER_WALL = 0.5;
const double EPS = 0.001;
const double DEATH_LINE = -5;

void render();
void update(int value);
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void resize(int width, int height);

Scene* currentScene;

int main(int argc, char* argv[]) {

    /* Inicijalizacija glut biblioteke i kreiranje prozora*/
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2,
                           (glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2);
    glutCreateWindow("SpaceMess v1.0");

    /* Registrovanje funkcija */
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutReshapeFunc(resize);
    glutTimerFunc(TIMER_INTERVAL, update, 0);

    currentScene = new Menu();

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    glutMainLoop();

    return 0;
}
void render() {
    
    glViewport(0, 0, WIDTH, HEIGHT);

    currentScene->render();

    glutSwapBuffers();
}
void keyboard(unsigned char key, int x,int y) {
    currentScene->getKeyDown(key);
}
void keyboardUp(unsigned char key, int x, int y) {
    currentScene->getKeyUp(key);
}
void update(int value) {
    if (value != 0)
        return;
    
    currentScene->update();

    glutPostRedisplay();
    glutTimerFunc(TIMER_INTERVAL, update, 0);
}
void resize(int width, int height) {
    /* Ne dozvoljavam menjanje velicine prozora */
    glutReshapeWindow(WIDTH, HEIGHT);
}