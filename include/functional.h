//
// Created by marcin on 15.01.17.
//

#pragma once

#include "../include/shared.h"
#include "../include/Ship.h"
#include "../include/Enemy.h"
#include "../include/Bullet.h"
#include "../include/Button.h"

namespace functional {
    // functions
    void
    handleEvents(sf::Event& event, sf::RenderWindow& window,
                 Ship& ship, bullet_Arr& bullets,
                 sf::Clock& clock, float& deltaTime);

    void
    drawScreen(sf::RenderWindow& window, Ship& ship, enemies_Arr& enemies,
               bullet_Arr& bullets, sf::Text& lives);

    void
    fireBullet(Ship& ship, bullet_Arr& bullets);

    void
    bulletsUpdate(bullet_Arr& bullets, float& deltaTime);

    void
    spawnEnemies(enemies_Arr& enemies);

    void
    enemiesUpdate(enemies_Arr& enemies, float& deltaTime);

    void
    checkCollisions(Ship& ship, enemies_Arr& enemies, bullet_Arr& bullets);
}
