#include "headers/Missile.hpp"

Missile::Missile(const Vector3& position, const Vector3& color, const Vector3& direction, double size, double speed) 
    : Entity(position, color, size, speed) {
    
    double intensity = sqrt((direction.x*direction.x)+(direction.y*direction.y)+(direction.z*direction.z));
    velocity.x = direction.x/intensity;
    velocity.y = direction.y/intensity;
    velocity.z = direction.z/intensity;
}

void Missile::update() {
    position += velocity * speed;
}
void Missile::render() {
    GLfloat ambientCoeffs[] = {0.1 , 0.1, 0.1, 1};
    GLfloat diffuseCoeffs[] = {color.x, color.y, color.z, 1};
    GLfloat specularCoeffs[] = {1, 1, 1, 1};
    GLfloat shininess = 20;

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientCoeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseCoeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularCoeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
        glTranslatef(position.x, position.y, position.z);
        glutSolidSphere(size, 30, 30);
    glPopMatrix();
}