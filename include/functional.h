//
// Created by marcin on 15.01.17.
//

#ifndef VSALIENS_FUNCTIONAL_H
#define VSALIENS_FUNCTIONAL_H

#include "../include/shared.h"
#include "../include/Character.h"
#include "../include/Ship.h"
#include "../include/Bullet.h"

namespace functional
{
    // constants
    const float OBJ_SPEED = 100;

    // functions
    void
    handleEvents(sf::Event& event, sf::Clock& clock,
                 sf::RenderWindow& window, Ship* ship,
                 bullet_Arr& bullets);

    void
    fireBullet(Ship* ship, bullet_Arr& bullets);

    void
    bulletsUpdate(bullet_Arr& bullets);
}
#endif //VSALIENS_FUNCTIONAL_H
