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

class Ship : public Character
{
public:
    Ship(const sf::Texture& texture);
    void reset();
    void addBullet();
    void updateCannonStatus();
    bool getCannonStatus();
    void fireBullet(bullets_Arr& bullets);
    void addLife();
    void removeLife();
    int getLives();
    int getBulletsLeft();
    int getMaxBullets();
private:
    int lives;
    int maxBullets;
    int bulletsLeft;
    sf::Clock reloadClock;
    bool reloadClockRestarted;
    bool canFire;
};
