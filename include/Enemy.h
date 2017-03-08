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

//typedef std::vector<Enemy> enemies_Arr;

class enemies_Arr : private std::vector<Enemy> {
public:
    typedef std::vector<Enemy> Vector;
    using Vector::clear;
    using Vector::at;
    using Vector::begin;
    using Vector::size_type;
    using Vector::size;
    using Vector::operator[];
    using Vector::push_back;
    using Vector::erase;
    using Vector constexpr;
private:
    //
};
