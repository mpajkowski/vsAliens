/**
 * vsAliens
 * main.cpp
 *
 * Class Ship
 */

#pragma once

#include "../include/shared.h"
#include "Character.h"
#include "Bullet.h"

class Ship : public Character {
public:
    Ship(const sf::Texture& texture);
    void updateCannonStatus();
    bool getCannonStatus();
    void fireBullet(bullets_Arr& bullets);
private:
    sf::Clock reloadClock;
    bool reloadClockRestarted;
    bool canFire = true;
};
