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
