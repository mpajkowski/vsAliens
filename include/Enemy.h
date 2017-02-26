/**
 * vsAliens
 * Enemy.h
 *
 * Class Enemy
 */

#pragma once

#include "../include/shared.h"
#include "../include/Character.h"
#include "../include/Ship.h"

class Enemy : public Character {
public:
    Enemy(const sf::Texture& texture);

    void
    randomMove(Ship& ship);
private:
    sf::Clock movementClock;
    bool holdMove = false;
    bool wantMoveLeft = false;
    bool wantMoveRight = false;
    bool wantMoveDown = false;
    bool wantMoveUp = false;
};

typedef std::vector<Enemy> enemies_Arr;
