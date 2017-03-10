/*
 * vsAliens
 * functional.cpp
 *
 * Events handling - implementation
 */

#include "../include/Ship.h"
#include "../include/Enemy.h"
#include "../include/functional.h"

void
functional::handleEvents(sf::Event& event, sf::RenderWindow& window,
                         Hud& hud, Ship& ship, bullets_Arr& bullets,
                         sf::Clock& clock, float& deltaTime) {
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed :
                window.close();
                break;
            case sf::Event::KeyPressed :
                if (event.key.code == sf::Keyboard::Q) {
                    window.close();
                } else if (event.key.code == sf::Keyboard::Space) {
                    if (!hud.getGameStatus()) {
                        hud.setGameStatus(true);
                    } else {
                        ship.fireBullet(bullets);
                    }
                }
            default :
                break;
        }
    }

    handleShipMovement(ship);
}

void
functional::handleShipMovement(Ship& ship) {
    ship.setMoveFlag(Ship::up, sf::Keyboard::isKeyPressed(sf::Keyboard::W));
    ship.setMoveFlag(Ship::down, sf::Keyboard::isKeyPressed(sf::Keyboard::S));
    ship.setMoveFlag(Ship::right, sf::Keyboard::isKeyPressed(sf::Keyboard::D));
    ship.setMoveFlag(Ship::left, sf::Keyboard::isKeyPressed(sf::Keyboard::A));
}

void
functional::gameOver(Hud& hud, Ship& ship, enemies_Arr& enemies, bullets_Arr& bullets,
            bonuses_Arr& bonuses) {
    ship.reset();
    enemies.reset();
    bullets.clear();
    bonuses.clear();

    hud.gameOver();
    hud.setGameStatus(false);
}

void
functional::drawScreen(sf::RenderWindow& window, Hud& hud, Ship& ship, enemies_Arr& enemies,
                       bullets_Arr& bullets, bonuses_Arr& bonuses) {
    window.clear(sf::Color::White);
    window.draw(ship);

    for (auto& enemy : enemies) {
        window.draw(enemy);
    }

    for (auto& bullet : bullets) {
        window.draw(bullet);
    }

    for (auto& bonus : bonuses) {
        window.draw(bonus);
    }

    window.draw(hud);

    window.display();
}

void
functional::enemyCollisions(Hud& hud, Ship& ship, enemies_Arr& enemies, bullets_Arr& bullets,
                            bonuses_Arr& bonuses) {
    for (uint i = 0; i < enemies.size();) {
        for (uint j = 0; j < bullets.size();) {
            if (bullets[ j ].getBounds().intersects(enemies[ i ].getBounds())) {
                bullets.erase(bullets.begin() + j);

                hud.updateScore(5);

                sf::Vector2f send = enemies[ i ].getPosition();
                bonuses.updatePos(send);
                bonuses.updateFragCounter(1);

                enemies.erase(enemies.begin() + i);
            }
            else ++j;
        }

        if (ship.getBounds().intersects(enemies[ i ].getBounds())) {
            ship.removeLife();
            ship.setPosition(500, 600);
            enemies.erase(enemies.begin() + i);
            if (ship.getLives() < 1) {
                gameOver(hud, ship, enemies, bullets, bonuses);
            }
        }
        else ++i;
    }
}

void
functional::bonusesCollisions(Hud& hud, Ship& ship, enemies_Arr& enemies, bonuses_Arr& bonuses) {
    for (uint i = 0; i < bonuses.size(); ++i) {
        if (ship.getBounds().intersects(bonuses[ i ].getBounds())) {
            switch (bonuses[ i ].type) {
                case Bonus::super_bullet :
                    hud.updateScore(enemies.size() * 3);
                    bonuses.updateFragCounter(enemies.size());
                    enemies.reset();
                    break;
                case Bonus::extra_life :
                    ship.addLife();
                    break;
                case Bonus::extra_bullet :
                    ship.addBullet();
                    break;
                default :
                    break;
            }
            bonuses.erase(bonuses.begin() + i);
        }
    }
}

void
functional::handleCollisions(Hud& hud, Ship& ship, enemies_Arr& enemies, bullets_Arr& bullets,
                            bonuses_Arr& bonuses) {
    enemyCollisions(hud, ship, enemies, bullets, bonuses);
    bonusesCollisions(hud, ship, enemies, bonuses);
}
