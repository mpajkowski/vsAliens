/**
 * vsAliens
 * main.cpp
 *
 * Class Enemy - implementation
 */

#include <random>
#include "../include/Enemy.h"

Enemy::Enemy(const sf::Texture& texture) :
        Character(texture, 30, 29, settings::enemy::MOVE_SPEED) {
    this->setPosition((rand() % settings::window::WIDTH - 30),
                      (rand() % settings::window::HEIGHT - 30) / 2);
}

void Enemy::randomMove() {
    float lastMove = movementClock.getElapsedTime().asSeconds();

    if (lastMove > 0.5 + rand() % 4
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
                wantMoveRight = rand() % 2;
            } else {
                wantMoveRight = false;
            }

            if (canMove(left)) {
                wantMoveLeft = rand() % 2;
            } else {
                wantMoveLeft = false;
            }

            if (canMove(up)) {
                wantMoveUp = rand() % 2;
            } else {
                wantMoveUp = false;
            }

            if (canMove(down)) {
                wantMoveDown = rand() % 2;
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
