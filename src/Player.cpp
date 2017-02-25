#include "headers/Player.hpp"

Player::Player(const Vector3& position, const Vector3& color, double size, double speed)
    : Killable(position, color, size, speed, 200) {
    
    left = right = false;
    readyToShoot = false;

    weapon = new Weapon(Vector3(1, 0, 1), 0.02, 0.1, -3, 50);

    aliveTimer = Timer();
    aliveTimer.start();
}
Player::~Player() {
    delete weapon;
}

void Player::update() {

    if (right) {
        velocity.x += MOVE_STEP;
        if (velocity.x >= speed) {
            velocity.x = speed;
        }
    } else if (left) {
        velocity.x -= MOVE_STEP;
        if (velocity.x <= -speed) {
            velocity.x = -speed;
        }
    } else {
        // ovaj deo koda resava problem "ukopavanja" igraca u mesto, tako sto polako smanjuje brzinu do nule
        if (velocity.x > 0) {
            velocity.x -= MOVE_STEP;
            if (velocity.x <= 0) {
                velocity.x = 0;
            }
        } else if (velocity.x < 0) {
            velocity.x += MOVE_STEP;
            if (velocity.x >= 0) {
                velocity.x = 0;
            }
        }
    }

    position.x += velocity.x;

    if (readyToShoot) {
        // ne dozvoljava se spam pritiskajuci dugme za pucanje
        weapon->addMissile(Vector3(0, 0, -1)); // igrac uvek puca pravo, zato ovakav argument
        readyToShoot = false;
    }
    weapon->setPosition(position); // postavljamo oruzje na poziciju igraca, kako bi rakete izletale gde treba
    weapon->update();

    if (!dead) {
        if (health <= 0) {
            health = 0;
            dead = true;
        }
    }
}
void Player::render() {

    // mozda u buducnosti srediti ovo za materijal, da ne bude hardcode
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
        glutSolidCube(size);
    glPopMatrix();

    weapon->render();
}

void Player::moveRight(bool right) {
    this->right = right;
}
void Player::moveLeft(bool left) {
    this->left = left;
}
void Player::setReadyToShoot(bool ready) {
    readyToShoot = ready;
}
int Player::getTimeAlive() const {
    return aliveTimer.getElapsedTime();
}