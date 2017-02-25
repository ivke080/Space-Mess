#include <cstdlib>
#include <ctime>
#include <GL/glut.h>
#include "headers/consts.hpp"
#include "headers/Background.hpp"

Background::Background() {
    initStars();
}
Background::~Background() {

}
void Background::render2D() {

    renderStars();
}
void Background::render3D() {

}
void Background::update() {

    updateStars();
}
void Background::initStars() {
    srand(time(NULL));

    for (int i = 0; i < MAX_NUM_STARS; i++) {
        stars[i].x = rand()%(WIDTH+1);
        stars[i].y = rand()%(HEIGHT+1);
        stars[i].vx = (stars[i].x - WIDTH/2)/(double)WIDTH;
        stars[i].vy = (stars[i].y - HEIGHT/2)/(double)HEIGHT;
    }
}
void Background::renderStars() {
    
    glColor3f(1, 1, 1);
    for (int i = 0; i < MAX_NUM_STARS; i++) {
        glBegin(GL_POLYGON);
            glVertex2f(stars[i].x, stars[i].y);
            glVertex2f(stars[i].x+1, stars[i].y);
            glVertex2f(stars[i].x+1, stars[i].y+1);
            glVertex2f(stars[i].x, stars[i].y+1);
        glEnd();
    }
}
void Background::updateStars() {

    
    for (int i = 0;i < MAX_NUM_STARS; i++) {
        stars[i].x += STAR_SPEED * stars[i].vx;
        stars[i].y += STAR_SPEED * stars[i].vy;

        // Ukoliko zvezda izleti sa ekrana, repozicioniram je negde oko centra
        if (stars[i].x > WIDTH || stars[i].x < 0
            || stars[i].y > HEIGHT || stars[i].y < 0) {
            
            stars[i].x = rand()%((WIDTH/2+150)-(WIDTH/2-150)+1)+(WIDTH/2-150);
            stars[i].y = rand()%((HEIGHT/2+150)-(HEIGHT/2-150)+1)+(HEIGHT/2-150);
            stars[i].vx = (stars[i].x - WIDTH/2)/(double)WIDTH;
            stars[i].vy = (stars[i].y - HEIGHT/2)/(double)HEIGHT;
        }
    }
}