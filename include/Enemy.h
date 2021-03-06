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

class Enemy : public Character
{
public:
    Enemy(const sf::Texture& texture, Ship& ship);

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

class enemies_Arr : public ObjectContainer<Enemy>
{
    public:
        enemies_Arr();
        void reset();
        void spawn (Ship& ship);
        void update(Ship& ship, float& deltaTime);
    private:
        sf::Clock spawnClock;
        int fragCounter;
};
