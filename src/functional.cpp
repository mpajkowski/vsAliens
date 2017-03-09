/*
 * vsAliens
 * functional.cpp
 *
 * Events handling - implementation
 */

#include "../include/Ship.h"
#include "../include/Enemy.h"
#include "../include/Bullet.h"
#include "../include/functional.h"

#include <random>

void
functional::handleEvents(sf::Event& event, sf::RenderWindow& window,
                         Ship& ship, bullets_Arr& bullets,
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
                    if (!stats::game::isActive) {
                        stats::game::isActive = true;
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
functional::gameOver(Hud& hud, enemies_Arr& enemies, bullets_Arr& bullets,
            bonuses_Arr& bonuses) {

    //reset stats
    stats::game::score = 0;
    stats::game::lives = 1;
    stats::bullet::maxBullets = settings::bullet::maxBullets;
    stats::bullet::bulletsLeft = settings::bullet::maxBullets;
    stats::bullet::speed = settings::bullet::speed;
    stats::enemy::fragCounter = 0;
    enemies.clear();
    bullets.clear();
    bonuses.clear();

    stats::game::isActive = false;
}

void
functional::drawScreen(sf::RenderWindow& window, Hud& hud, Ship& ship, enemies_Arr& enemies,
                       bullets_Arr& bullets, bonuses_Arr& bonuses) {
    window.clear(sf::Color::White);
    window.draw(ship);

    for (unsigned int i = 0; i < enemies.size(); ++i) {
        window.draw(enemies[ i ]);
    }

    for (unsigned int i = 0; i < bullets.size(); ++i) {
        window.draw(bullets[ i ]);
    }

    for (unsigned int i = 0; i < bonuses.size(); ++i) {
        window.draw(bonuses[ i ]);
    }

    window.draw(hud);

    window.display();
}

void
functional::enemyCollisions(Hud& hud, Ship& ship, enemies_Arr& enemies, bullets_Arr& bullets,
                            bonuses_Arr& bonuses) {
    for (unsigned int i = 0; i < enemies.size(); ++i) {
        for (unsigned int j = 0; j < bullets.size(); ++j) {
            if (bullets[ j ].getBounds().intersects(enemies[ i ].getBounds())) {
                bullets.erase(bullets.begin() + j);
                stats::enemy::lastPos = enemies[ i ].getPosition();
                ++stats::enemy::fragCounter;
                enemies.erase(enemies.begin() + i);
                stats::game::score += 5;
            }
        }

        if (ship.getBounds().intersects(enemies[ i ].getBounds())) {
            stats::game::lives--;
            ship.setPosition(500, 600);
            enemies.erase(enemies.begin() + i);
            if (stats::game::lives < 1) {
                gameOver(hud, enemies, bullets, bonuses);
            }
        }
    }
}

void
functional::bonusesCollisions(Ship& ship, enemies_Arr& enemies, bonuses_Arr& bonuses) {
    for (unsigned int i = 0; i < bonuses.size(); ++i) {
        if (ship.getBounds().intersects(bonuses[ i ].getBounds())) {
            switch (bonuses[ i ].type) {
                case Bonus::super_bullet :
                    stats::game::score += (enemies.size() * 3);
                    stats::enemy::fragCounter += enemies.size();
                    enemies.clear();
                    break;
                case Bonus::extra_life :
                    ++stats::game::lives;
                    break;
                case Bonus::extra_bullet :
                    ++stats::bullet::maxBullets;
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
    bonusesCollisions(ship, enemies, bonuses);
}
