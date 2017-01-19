//
// Created by marcin on 15.01.17.
//

#ifndef VSALIENS_SHIP_H
#define VSALIENS_SHIP_H
#include "../include/Character.h"

class Ship : public Character
{
public:
    Ship(const sf::Texture& texture);
    void shoot();
};


#endif //VSALIENS_SHIP_H
