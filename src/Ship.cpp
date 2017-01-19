//
// Created by marcin on 15.01.17.
//

#include "../include/shared.h"
#include "../include/Ship.h"

Ship::Ship(const sf::Texture &texture):
    Character(texture, 30, 24)
{
    this->setPosition(500, 600);
}