#include "headers/Enemy.hpp"

Enemy::Enemy(const Vector3& position, const Vector3& color, double size, double speed, double health, 
            Player* player) : Killable(position, color, size, speed, health) {
    
    this->player = player;
    hitTimer = Timer();
    hitColor = Vector3(1, 0, 0);
    tempColor = color;
}
void Enemy::update() {
    /* Ovde se kontrolise duzina trajanja crvenila, kada dodje do kolizije sa projektilom */
    if (!hitTimer.isSet()) {
        if (hit) {
            hitTimer.start();
            tempColor = hitColor;
            hit = false;
        }
    } else {
        if (hitTimer.getElapsedTime() > 0.1) {
            hitTimer.stop();
            if (!dying) {
                tempColor = color;
            }
        }
    }
    /* Ako HP padne ispod 0, pocinje dying fleg se postavlja na true i pocinje sekvenca umiranja */
    if (!dying) {
        if (health <= 0) {
            health = 0;
            dying = true;
            tempColor = hitColor;
        }
    }
}
void Enemy::render() {

    GLfloat ambientCoeffs[] = {0.1 , 0.1, 0.1, 1};
    GLfloat diffuseCoeffs[] = {tempColor.x, tempColor.y, tempColor.z, 1};
    GLfloat specularCoeffs[] = {1, 1, 1, 1};
    GLfloat shininess = 20;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientCoeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseCoeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularCoeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
        glTranslatef(position.x, position.y, position.z);
        glutSolidCube(size);
    glPopMatrix();
}

double Enemy::getCrashDamage() const {
    return crashDamage;
}