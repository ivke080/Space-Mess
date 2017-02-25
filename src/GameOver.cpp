#include "headers/GameOver.hpp"

GameOver::GameOver(int seconds) {
    text = "I know you want to change the source code and make it easier, don't you?";
    os << "Dead already? Only " << seconds << " seconds? Pathetic!";
    alive = os.str();

    msgTimer = Timer();
    msgTimer.start();
}

void GameOver::update() {
    if (msgTimer.getElapsedTime() > 5) {
        msgTimer.stop();
        delete currentScene;
        currentScene = new Menu();
    }
}
void GameOver::render() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Pozicioniranje i ispisivanje poruka na zavrsnom ekranu */
    glColor3f(1, 1, 1);

    glRasterPos2f(WIDTH/2 - (alive.size()/2) * 9, HEIGHT/2 - 100);
    for (int i = 0; alive[i] != '\0'; ++i)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, alive[i]);

    glRasterPos2f(WIDTH/2 - (text.size()/2) * 9, HEIGHT/2);
    for (int i = 0; text[i] != '\0'; ++i)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
}
