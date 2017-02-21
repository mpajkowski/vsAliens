/**
 * vsAliens
 * Enemy.h
 *
 * Class Enemy
 */

#pragma once

#include "../include/shared.h"
#include "../include/Character.h"

class Enemy : public Character {
public:
    Enemy(const sf::Texture& texture);

    void
    randomMove();
private:
    time_t lastMove = time(NULL);
    bool holdMove = false;
    bool wantMoveLeft = false;
    bool wantMoveRight = false;
    bool wantMoveDown = false;
    bool wantMoveUp = false;
};

typedef std::vector<Enemy> enemies_Arr;