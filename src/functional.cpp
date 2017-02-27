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
#include "../include/stats.h"

#include <random>

void
functional::handleEvents(sf::Event& event, sf::RenderWindow& window,
                         Ship& ship, bullets_Arr& bullets,
                         sf::Text& lives, sf::Clock& clock,
                         float& deltaTime) {
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
                        lives.setPosition(settings::window::WIDTH - 100, 0);
                    } else {
                        fireBullet(ship, bullets);
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
functional::gameOver(sf::Text& lives, enemies_Arr& enemies, bullets_Arr& bullets,
            bonuses_Arr& bonuses) {
    lives.setString("Game Over");
    lives.setPosition(settings::window::WIDTH - 150, 0);

    //reset stats
    stats::game::score = 0;
    stats::game::lives = 1;
    stats::bullet::maxBullets = settings::bullet::maxBullets;
    stats::bullet::speed = settings::bullet::speed;
    enemies.clear();
    bullets.clear();
    bonuses.clear();

    stats::game::isActive = false;
}

void
functional::drawScreen(sf::RenderWindow& window, Ship& ship, enemies_Arr& enemies,
                       bullets_Arr& bullets, bonuses_Arr& bonuses,
                       sf::Text& score, sf::Text& lives, sf::Text& avBullets) {
    window.clear(sf::Color::White);
    window.draw(ship);

    for (enemies_Arr::size_type i = 0; i < enemies.size(); ++i) {
        window.draw(enemies[ i ]);
    }

    for (bullets_Arr::size_type i = 0; i < bullets.size(); ++i) {
        window.draw(bullets[ i ]);
    }

    for (bonuses_Arr::size_type i = 0; i < bonuses.size(); ++i) {
        window.draw(bonuses[ i ]);
    }

    window.draw(score);
    window.draw(lives);
    window.draw(avBullets);

    window.display();
}

void
functional::fireBullet(Ship& ship, bullets_Arr& bullets) {

    if (canFire()) {
        Bullet newBullet(ship);
        bullets.push_back(newBullet);
        --stats::bullet::bulletsLeft;
    }
}

bool
functional::canFire() {
    static bool canFire = true;
    static sf::Clock reloadClock;
    static bool reloadClockRestarted;

    if (stats::bullet::bulletsLeft == 0) {
        canFire = false;

        if (!reloadClockRestarted) {
            reloadClock.restart();
            reloadClockRestarted = true;
        }

        if (reloadClock.getElapsedTime().asSeconds() >= 3) {
            reloadClockRestarted = false;
            stats::bullet::bulletsLeft = stats::bullet::maxBullets;
            canFire = true;
        }
    }

    return canFire;
}

void
functional::bulletsUpdate(bullets_Arr& bullets, float& deltaTime) {
    for (bullets_Arr::size_type i = 0; i < bullets.size(); ++i) {
        bullets[ i ].updateBullet(deltaTime);

        if (bullets[ i ].getPos().y < 0) {
            bullets.erase(bullets.begin() + i);
        }
    }
}

void
functional::spawnEnemies(enemies_Arr& enemies) {
    static sf::Clock spawnClock;
    float lastSpawnTime = spawnClock.getElapsedTime().asSeconds();

    if (lastSpawnTime > 1) {
        Enemy newEnemy = Enemy(settings::textures::enemyTexture);
        enemies.push_back(newEnemy);
        spawnClock.restart();
    }
}

void
functional::spawnBonuses(bonuses_Arr& bonuses) {
    if (stats::enemy::fragCounter >= 5) {
        Bonus newBonus(stats::enemy::lastPos.x,
                       stats::enemy::lastPos.y,
                       static_cast<Bonus::Type>(rand() % 3));
        bonuses.push_back(newBonus);
        stats::enemy::fragCounter = 0;
    }
}

void
functional::enemiesUpdate(Ship& ship, enemies_Arr& enemies, float& deltaTime) {
    spawnEnemies(enemies);

    for (enemies_Arr::size_type i = 0; i < enemies.size(); ++i) {
        enemies[ i ].randomMove(ship);
        enemies[ i ].updatePos(deltaTime);
    }
}

void
functional::updateBonuses(bonuses_Arr& bonuses) {
    spawnBonuses(bonuses);

    for (bonuses_Arr::size_type i = 0; i < bonuses.size(); ++i) {
        if (bonuses[ i ].getSpawnTime() > 5) {
            bonuses.erase(bonuses.begin() + i);
        }
    }
}

void
functional::updateScore(sf::Text& score) {
    std::string msg = "Score: " + std::to_string(stats::game::score);
    score.setString(msg);
}

void
functional::updateLives(sf::Text& lives) {
    std::string msg = "Lives: " + std::to_string(stats::game::lives);
    lives.setString(msg);
}

void
functional::updateAvBullets(sf::Text& avBullets) {
    std::string msg;

    for (int i = 0; i < stats::bullet::bulletsLeft; ++i) {
        msg += "* ";
    }

    avBullets.setString(msg);
}

void
functional::enemyCollisions(Ship& ship, enemies_Arr& enemies, bullets_Arr& bullets,
                            bonuses_Arr& bonuses, sf::Text& lives) {
    for (enemies_Arr::size_type i = 0; i < enemies.size(); ++i) {
        for (bullets_Arr::size_type j = 0; j < bullets.size(); ++j) {
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
            if (stats::game::lives < 1) {
                gameOver(lives, enemies, bullets, bonuses);
            }
        }
    }
}

void
functional::bonusesCollisions(Ship& ship, enemies_Arr& enemies, bonuses_Arr& bonuses) {
    for (bonuses_Arr::size_type i = 0; i < bonuses.size(); ++i) {
        if (ship.getBounds().intersects(bonuses[ i ].getBounds())) {
            switch (bonuses[ i ].type) {
                case Bonus::super_bullet :
                    stats::game::score += (enemies.size() & 3);
                    stats::enemy::fragCounter += enemies.size();
                    enemies.clear();
                    break;
                case Bonus::extra_life :
                    ++stats::game::lives;
                    break;
                case Bonus::extra_bullet :
                    ++stats::bullet::maxBullets;
                    //++stats::bullet::bulletsLeft;
                    break;
                default :
                    break;
            }
            bonuses.erase(bonuses.begin() + i);
        }
    }
}

void
functional::handleCollisions(Ship& ship, enemies_Arr& enemies, bullets_Arr& bullets,
                            bonuses_Arr& bonuses, sf::Text& lives) {
    enemyCollisions(ship, enemies, bullets, bonuses, lives);
    bonusesCollisions(ship, enemies, bonuses);
}
