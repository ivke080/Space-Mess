#include "headers/Hud.hpp"

Hud::Hud(Player* player, Boss* boss) {
    this->player = player;
    this->boss = boss;
    bossHealth = boss->getHealth();

    bar.height = 20;
    bar.x = 50;
    bar.y = 20;
}

void Hud::update() {
    bar.width = boss->getHealth()/bossHealth * (WIDTH-bar.x*2);
}
void Hud::render() {

    glClear(GL_DEPTH_BUFFER_BIT); // da ne bi zvezdice isle preko bar-a 

    os << "Health: " << player->getHealth();
    std::string hs = os.str(); 
    os.str(std::string()); // cisti se stringstream

    glColor3f(1, 1, 1);
    glRasterPos2f(20, HEIGHT-20);

    for (int i = 0; hs[i] != '\0'; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, hs[i]);
    }

    os << "Time: " << player->getTimeAlive() << "s";
    std::string alive = os.str();
    os.str(std::string());

    glRasterPos2f(WIDTH-150, HEIGHT-20);
    for (int i = 0; alive[i] != '\0'; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, alive[i]);
    }

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(bar.x, bar.y);
        glVertex2f(bar.x + bar.width, bar.y);
        glVertex2f(bar.x + bar.width, bar.y + bar.height);
        glVertex2f(bar.x, bar.y + bar.height);
    glEnd();
}