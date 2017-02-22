//
// Created by marcin on 15.01.17.
//

#pragma once

#include "../include/shared.h"
#include "../include/Ship.h"
#include "../include/Enemy.h"
#include "../include/Bullet.h"

namespace functional {
    // vsAliens functional stuff

    /////////////////////////////////////////////////////////////////////
    // in-game keyboard events
    void
    handleEvents(sf::Event& event, sf::RenderWindow& window,
                 Ship& ship, bullet_Arr& bullets,
                 sf::Text& lives, sf::Clock& clock,
                 float& deltaTime);

    /////////////////////////////////////////////////////////////////////
    // draw all sf::Drawables
    void
    drawScreen(sf::RenderWindow& window, Ship& ship, enemies_Arr& enemies,
               bullet_Arr& bullets, sf::Text& score, sf::Text& lives);

    /////////////////////////////////////////////////////////////////////
    // game over
    void
    gameOver(sf::Text& lives);

    /////////////////////////////////////////////////////////////////////
    // firing bullets
    void
    fireBullet(Ship& ship, bullet_Arr& bullets);

    /////////////////////////////////////////////////////////////////////
    // updating bullets' positions
    void
    bulletsUpdate(bullet_Arr& bullets, float& deltaTime);

    /////////////////////////////////////////////////////////////////////
    // spawning enemies in given amount of time
    void
    spawnEnemies(enemies_Arr& enemies);

    /////////////////////////////////////////////////////////////////////
    // updating enemies' pos; handling random movement
    void
    enemiesUpdate(enemies_Arr& enemies, float& deltaTime);

    /////////////////////////////////////////////////////////////////////
    // updating score text field
    void
    updateScore(sf::Text& score);

    /////////////////////////////////////////////////////////////////////
    // updating score text field
    void
    updateLives(sf::Text& lives);

    /////////////////////////////////////////////////////////////////////
    // handling objects' collisions
    void
    checkCollisions(Ship& ship, enemies_Arr& enemies, bullet_Arr& bullets,
                    sf::Text& lives);
}
