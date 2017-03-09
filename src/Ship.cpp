/**
 * vsAliens
 * Ship.cpp
 *
 * Class Ship methods - implementation
 */

#include "../include/Ship.h"

Ship::Ship(const sf::Texture& texture) :
        Character(texture, 30, 24, settings::ship::MOVE_SPEED) {
    this->setPosition(500, 600);
}

void
Ship::updateCannonStatus() {
    if (stats::bullet::bulletsLeft < 1) {
        canFire = false;

        if (!reloadClockRestarted) {
            reloadClock.restart();
            reloadClockRestarted = true;
        }

        if (reloadClock.getElapsedTime().asSeconds() >= 3) {
            reloadClockRestarted = false;
            stats::bullet::bulletsLeft = stats::bullet::maxBullets;
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
        --stats::bullet::bulletsLeft;
    }
}

bool
Ship::getCannonStatus() {
    return canFire;
}
