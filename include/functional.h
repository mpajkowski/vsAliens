//
// Created by marcin on 15.01.17.
//

#pragma once

#include "../include/shared.h"
#include "../include/Ship.h"
#include "../include/Enemy.h"
#include "../include/Bullet.h"
#include "../include/Bonus.h"
#include "../include/Hud.h"

namespace functional {
    // vsAliens functional stuff

    /////////////////////////////////////////////////////////////////////
    // in-game keyboard events
    void
    handleEvents(sf::Event& event, sf::RenderWindow& window,
                 Ship& ship, bullets_Arr& bullets,
                 sf::Clock& clock, float& deltaTime);

    /////////////////////////////////////////////////////////////////////
    //
    void
    handleShipMovement(Ship& ship);

    /////////////////////////////////////////////////////////////////////
    // draw all sf::Drawables
    void
    drawScreen(sf::RenderWindow& window, Hud& hud, Ship& ship, enemies_Arr& enemies,
               bullets_Arr& bullets, bonuses_Arr& bonuses);

    /////////////////////////////////////////////////////////////////////
    // game over and reset stats
    void
    gameOver(Hud& hud, enemies_Arr& enemies, bullets_Arr& bullets,
            bonuses_Arr& bonuses);

    /////////////////////////////////////////////////////////////////////
    //
    void
    enemyCollisions(Hud& hud, Ship& ship, enemies_Arr& enemies, bullets_Arr& bullets,
                    bonuses_Arr& bonuses);

    /////////////////////////////////////////////////////////////////////
    //
    void
    bonusesCollisions(Ship& ship, enemies_Arr& enemies, bonuses_Arr& bonuses);

    /////////////////////////////////////////////////////////////////////
    // handling objects' collisions
    void
    handleCollisions(Hud& hud, Ship& ship, enemies_Arr& enemies, bullets_Arr& bullets,
                    bonuses_Arr& bonuses);
}
