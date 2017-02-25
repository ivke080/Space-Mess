#include <GL/glut.h>
#include "headers/GameScene.hpp"

GameScene::GameScene() {
    pause = false;
    background = new Background();
    player = new Player(Vector3(0, 0, 1), Vector3(0, 0.808, .820), 0.08, 0.02);
    boss = new Boss(Vector3(0, 0, -3), player);
    hud = new Hud(player, boss);
    bots = new BotArmy(boss, player);
    initLight();
}
GameScene::~GameScene() {
    delete background;
    delete player;
    delete boss;
    delete hud;
    delete bots;
}
void GameScene::update() {
    if (!pause) {
        background->update();

        Collision::playerWall(*player, -PLAYER_WALL, PLAYER_WALL);
        Collision::killableToWeapon(player, boss->getWeapon());
        player->update();
        Collision::killableToWeapon(boss, player->getWeapon());
        boss->update();
        bots->update();
        
        hud->update();

        if (boss->isDead()) {
            delete currentScene;
            currentScene = new Menu();
        }
        if (player->isDead()) {
            int alive = player->getTimeAlive(); // jer se poziva destruktor ispod, pa se igrac unistava
            delete currentScene;
            currentScene = new GameOver(alive);
        }
    }
        
}
void GameScene::render() {
    
    // 2D iscrtavanje
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    background->render2D();
    hud->render();

    // 3D iscrtavanje
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, WIDTH/(double)HEIGHT, 0.1, 50);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0.5, 2, 0, 0, 0, 0, 1, 0);
    glClear(GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    // ovde crtati
    player->render();
    boss->render();
    bots->render();

    glDisable(GL_LIGHTING); // Ovo neophodno da bi se iscrtale zvezde u pozadini
}
void GameScene::getKeyDown(unsigned char key) {

    switch (key) {
        case 27:
            exit(0);
            break;
        case 'd':
        case 'D':
            player->moveRight(true);
            break;
        case 'a':
        case 'A':
            player->moveLeft(true);
            break;
        case 32:
            player->setReadyToShoot(false);
            break;
    }
}
void GameScene::getKeyUp(unsigned char key) {
    
    switch (key) {
        case 'd':
        case 'D':
            player->moveRight(false);
            break;
        case 'a':
        case 'A':
            player->moveLeft(false);
            break;
        case 32:
            player->setReadyToShoot(true);
            break;
        case 'p':
        case 'P':
            pause = !pause;
            break;
    }
}
void GameScene::initLight() {
    GLfloat lightPosition[] = {20.0, 10.0, 8.0, 1};
    GLfloat lightAmbient[] = {0.2, 0.2, 0.2, 1};
    GLfloat lightDiffuse[] = {0.8, 0.8, 0.8, 1};
    GLfloat lightSpecular[] = {1.0, 1.0, 1.0, 1};

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
}