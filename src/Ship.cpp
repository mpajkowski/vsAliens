/**
 * vsAliens
 * Ship.cpp
 *
 * Class Ship methods - implementation
 */

#include "../include/Ship.h"

Ship::Ship(const sf::Texture& texture) :
        Character(texture, 30, 24, settings::ship::MOVE_SPEED) {
    reset();
}

void
Ship::reset() {
    this->setPosition(500, 600);
    canFire = true;
    reloadClockRestarted = false;
    lives = 1;
    maxBullets = settings::bullet::maxBullets;
    bulletsLeft = maxBullets;
}

void
Ship::updateCannonStatus() {
    if (bulletsLeft < 1) {
        canFire = false;

        if (!reloadClockRestarted) {
            reloadClock.restart();
            reloadClockRestarted = true;
        }

        if (reloadClock.getElapsedTime().asSeconds() >= 3) {
            reloadClockRestarted = false;
            bulletsLeft = maxBullets;
            canFire = true;
        }
    }
    else canFire = true;
}

void
Ship::fireBullet(bullets_Arr& bullets) {
    if (canFire) {
        Bullet newBullet(getPosition());
        bullets.push_back(newBullet);
        --bulletsLeft;
    }
}

void
Ship::addBullet() {
    ++this->maxBullets;
}

bool
Ship::getCannonStatus() {
    return canFire;
}

int
Ship::getBulletsLeft() {
    return bulletsLeft;
}

int
Ship::getMaxBullets() {
    return maxBullets;
}

void
Ship::addLife() {
    ++this->lives;
}

void
Ship::removeLife() {
    --this->lives;
}

int
Ship::getLives() {
    return this->lives;
}
