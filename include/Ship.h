/**
 * vsAliens
 * main.cpp
 *
 * Class Ship
 */

#pragma once

#include "../include/shared.h"
#include "Character.h"

class Ship : public Character {
public:
    Ship(const sf::Texture& texture);
    void addLife();
    void removeLife();
private:
    int lives;
};