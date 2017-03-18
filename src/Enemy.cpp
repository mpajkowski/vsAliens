/**
 * vsAliens
 * main.cpp
 *
 * Class Enemy - implementation
 */

#include <random>
#include "../include/Enemy.h"


Enemy::Enemy(const sf::Texture& texture, Ship& ship) :
        Character(texture, 30, 29, settings::enemy::MOVE_SPEED) {
    sf::Vector2i pos;

    do {
        pos.x = rand() % settings::window::WIDTH - 30;
        pos.y = 3 * (rand() % settings::window::HEIGHT - 30) / 4;
    }
    while (ship.getPosition().x - pos.x <= 150 &&
           pos.x - ship.getPosition().x <= 150 &&
           ship.getPosition().y - pos.y <= 150 &&
           pos.y - ship.getPosition().y <= 150);

    this->setPosition(pos.x, pos.y);
}

void Enemy::randomMove(Ship& ship) {

    float lastMove = movementClock.getElapsedTime().asSeconds();

    if (lastMove > 0.4 + ((float) rand() / (float) (RAND_MAX / 3))
        || (!canMove(right))
        || (!canMove(down))
        || (!canMove(left))
        || (!canMove(up))) {

        setMoveFlag(Enemy::right, false);
        setMoveFlag(Enemy::down, false);
        setMoveFlag(Enemy::left, false);
        setMoveFlag(Enemy::up, false);

        wantMoveRight = false;
        wantMoveDown = false;
        wantMoveLeft = false;
        wantMoveUp = false;

        while (!((wantMoveLeft xor wantMoveRight) || (wantMoveUp xor wantMoveDown))) {
            if (canMove(right)) {
                wantMoveRight = this->getPosition().x > ship.getPosition().x ? false : bool(rand() % 2);
            } else {
                wantMoveRight = false;
            }

            if (canMove(left)) {
                wantMoveLeft = this->getPosition().x < ship.getPosition().x ? false : bool(rand() % 2);
            } else {
                wantMoveLeft = false;
            }

            if (canMove(up)) {
                wantMoveUp = this->getPosition().y < ship.getPosition().y ? false : bool(rand() % 2);
            } else {
                wantMoveUp = false;
            }

            if (canMove(down)) {
                wantMoveDown = this->getPosition().y > ship.getPosition().y ? false : bool(rand() % 2);
            } else {
                wantMoveDown = false;
            }
        }

        if (wantMoveUp) {
            setMoveFlag(Enemy::up, true);
        }
        if (wantMoveDown) {
            setMoveFlag(Enemy::down, true);
        }
        if (wantMoveRight) {
            setMoveFlag(Enemy::right, true);
        }
        if (wantMoveLeft) {
            setMoveFlag(Enemy::left, true);
        }

        movementClock.restart();
    }
}

///////////////////////////////////////////////////////////////////////////////////////
enemies_Arr::enemies_Arr() {
    reset();
}

void
enemies_Arr::reset() {
    fragCounter = 0;
    this->clear();
}

void
enemies_Arr::spawn(Ship& ship) {
    if (spawnClock.getElapsedTime().asSeconds() > 1) {
        Enemy newEnemy = Enemy(settings::textures::enemyTexture, ship);
        push_back(newEnemy);
        spawnClock.restart();
    }
}

void
enemies_Arr::update(Ship& ship, float& deltaTime) {
    spawn(ship);

    for (uint i = 0; i < size(); ++i) {
        at(i).randomMove(ship);
        at(i).updatePos(deltaTime);
    }
}
