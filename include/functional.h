//
// Created by marcin on 15.01.17.
//

#pragma once

#include "../include/shared.h"
#include "../include/Ship.h"
#include "../include/Enemy.h"
#include "../include/Bullet.h"
#include "../include/Bonus.h"

namespace functional {
    // vsAliens functional stuff

    /////////////////////////////////////////////////////////////////////
    // in-game keyboard events
    void
    handleEvents(sf::Event& event, sf::RenderWindow& window,
                 Ship& ship, bullets_Arr& bullets,
                 sf::Text& lives, sf::Clock& clock,
                 float& deltaTime);

    /////////////////////////////////////////////////////////////////////
    //
    void
    handleShipMovement(Ship& ship);

    /////////////////////////////////////////////////////////////////////
    // draw all sf::Drawables
    void
    drawScreen(sf::RenderWindow& window, Ship& ship, enemies_Arr& enemies,
               bullets_Arr& bullets, bonuses_Arr& bonuses,
               sf::Text& score, sf::Text& lives, sf::Text& avBullets);

    /////////////////////////////////////////////////////////////////////
    // game over and reset stats
    void
    gameOver(sf::Text& lives, enemies_Arr& enemies, bullets_Arr& bullets,
            bonuses_Arr& bonuses);

    /////////////////////////////////////////////////////////////////////
    // spawning bonuses
    void
    spawnBonuses(bonuses_Arr& bonuses);

    /////////////////////////////////////////////////////////////////////
    // updating bonuses
    void
    updateBonuses(bonuses_Arr& bonuses);

    /////////////////////////////////////////////////////////////////////
    // updating score text field
    void
    updateScore(sf::Text& score);

    /////////////////////////////////////////////////////////////////////
    // updating score text field
    void
    updateLives(sf::Text& lives);

    /////////////////////////////////////////////////////////////////////
    // updating avBullets text field
    void
    updateAvBullets(sf::Text& avBullets);

    /////////////////////////////////////////////////////////////////////
    //
    void
    enemyCollisions(Ship& ship, enemies_Arr& enemies, bullets_Arr& bullets,
                    bonuses_Arr& bonuses, sf::Text& lives);

    /////////////////////////////////////////////////////////////////////
    //
    void
    bonusesCollisions(Ship& ship, enemies_Arr& enemies, bonuses_Arr& bonuses);

    /////////////////////////////////////////////////////////////////////
    // handling objects' collisions
    void
    handleCollisions(Ship& ship, enemies_Arr& enemies, bullets_Arr& bullets,
                    bonuses_Arr& bonuses, sf::Text& lives);
}
