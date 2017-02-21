/**
 * vsAliens
 * functional.cpp
 *
 * Events handling - implementation
 */

#include "../include/Ship.h"
#include "../include/Enemy.h"
#include "../include/Bullet.h"
#include "../include/Button.h"
#include "../include/functional.h"
#include "../include/stats.h"

void
functional::handleEvents(sf::Event& event, sf::RenderWindow& window,
                         Ship& ship, bullet_Arr& bullets,
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
                    fireBullet(ship, bullets);
                }
                break;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //move up
    {
        ship.setMoveFlag(Ship::up, true);
    } else {
        ship.setMoveFlag(Ship::up, false);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //move down
    {
        ship.setMoveFlag(Ship::down, true);
    } else {
        ship.setMoveFlag(Ship::down, false);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //move right
    {
        ship.setMoveFlag(Ship::right, true);
    } else {
        ship.setMoveFlag(Ship::right, false);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //move left
    {
        ship.setMoveFlag(Ship::left, true);
    } else {
        ship.setMoveFlag(Ship::left, false);
    }
}

void
functional::drawScreen(sf::RenderWindow& window, Ship& ship, enemies_Arr& enemies,
                       bullet_Arr& bullets) {
    window.clear(sf::Color::White);
    window.draw(ship);

    for (enemies_Arr::size_type i = 0; i < enemies.size(); ++i) {
        window.draw(enemies[ i ]);
    }

    for (bullet_Arr::size_type i = 0; i < bullets.size(); ++i) {
        window.draw(bullets[ i ]);
    }

    window.display();
}

void
functional::fireBullet(Ship& ship, bullet_Arr& bullets) {
    Bullet newBullet(ship);
    bullets.push_back(newBullet);
}

void
functional::bulletsUpdate(bullet_Arr& bullets, float& deltaTime) {
    for (bullet_Arr::size_type i = 0; i < bullets.size(); ++i) {
        bullets[ i ].updateBullet(deltaTime);

        if (bullets[ i ].getPos().y < 0) {
            bullets.erase(bullets.begin() + i);
        }
    }
}

void
functional::spawnEnemies(enemies_Arr& enemies) {
    time_t now = time(NULL);
    time_t* lastSpawn = &stats::enemy::lastSpawnTime;

    sf::Texture const* enemyTexture = &settings::textures::enemyTexture;
    if (difftime(now, *lastSpawn) > 1.5) {
        Enemy newEnemy = Enemy(*enemyTexture);
        enemies.push_back(newEnemy);
        *lastSpawn = now;
    }
}

void
functional::enemiesUpdate(enemies_Arr& enemies, float& deltaTime) {
    spawnEnemies(enemies);

    for (enemies_Arr::size_type i = 0; i < enemies.size(); ++i) {
        enemies[i].randomMove();
        enemies[i].updatePos(deltaTime);
    }
}

void
functional::checkCollisions(Ship& ship, enemies_Arr& enemies, bullet_Arr& bullets) {
    for (enemies_Arr::size_type i = 0; i < enemies.size(); ++i) {
        for (bullet_Arr::size_type j = 0; j < bullets.size(); ++j) {
            if (bullets[ j ].getBounds().intersects(enemies[ i ].getBounds())) {
                bullets.erase(bullets.begin() + j);
                enemies.erase(enemies.begin() + i);
            }
        }

        if (ship.getBounds().intersects(enemies[ i ].getBounds())) {
            ship.removeLife();
            ship.setPosition(settings::window::HEIGHT - 50, settings::window::WIDTH / 2);
        }
    }
}