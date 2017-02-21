/**
 * vsAliens
 * main.cpp
 *
 * Class Character - implementation
 */

#include "../include/Character.h"

Character::Character(const sf::Texture& texture, float x, float y, float speed) {
    sprite.setTexture(texture);
    sprite.setOrigin(x, y);
    this->speed = speed;
}

void
Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void
Character::updatePos(float& delta) {

    confirmMove();

    if (getMoveFlag(left)) {
        sprite.move(-matchSpeed() * delta, 0);
    }

    if (getMoveFlag(right)) {
        sprite.move(matchSpeed() * delta, 0);
    }

    if (getMoveFlag(down)) {
        sprite.move(0, matchSpeed() * delta);
    }

    if (getMoveFlag(up)) {
        sprite.move(0, -matchSpeed() * delta);
    }
}

bool
Character::getMoveFlag(Dir dir) {
    using std::endl;

    bool flagValue;
    switch (dir) {
        case left :
            flagValue = isMovingLeft;
            break;
        case right :
            flagValue = isMovingRight;
            break;
        case down :
            flagValue = isMovingDown;
            break;
        case up :
            flagValue = isMovingUp;
            break;
        default:
            break;
    }

    return flagValue;
}

void
Character::confirmMove() {
    if (getMoveFlag(left) && !canMove(left)) {
        setMoveFlag(left, false);
    }

    if (getMoveFlag(right) && !canMove(right)) {

        setMoveFlag(right, false);
    }

    if (getMoveFlag(up) && !canMove(up)) {

        setMoveFlag(up, false);
    }
    if (getMoveFlag(down) && !canMove(down)) {

        setMoveFlag(down, false);
    }
}

bool
Character::canMove(Dir dir) {
    bool canMove;

    switch (dir) {
        case right :
            canMove = (sprite.getPosition().x <= settings::window::WIDTH - 30) ? true : false;
            break;
        case left :
            canMove = (sprite.getGlobalBounds().left >= 0) ? true : false;
            break;
        case up :
            canMove = (sprite.getGlobalBounds().top >= 0) ? true : false;
            break;
        case down :
            canMove = (sprite.getPosition().y <= settings::window::HEIGHT - 24) ? true : false;
            break;
    }

    return canMove;
}

sf::Vector2f
Character::getPosition() {
    return sprite.getPosition();
}

void
Character::setMoveFlag(Dir dir, bool isMoving) {
    switch (dir) {
        case right :
            this->isMovingRight = isMoving;
            break;
        case left :
            this->isMovingLeft = isMoving;
            break;
        case up :
            this->isMovingUp = isMoving;
            break;
        case down :
            this->isMovingDown = isMoving;
            break;
    }
}

float
Character::matchSpeed() {
    using std::sqrt;
    int currentSpeed = speed;

    if ((isMovingUp xor isMovingDown) xor (isMovingLeft xor isMovingRight)) {
        currentSpeed = speed;
    } else {
        currentSpeed = (speed * sqrt(2) / 2);
    }

    return currentSpeed;
}

void
Character::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

sf::Sprite
Character::getSprite() {
    return sprite;
}

sf::FloatRect
Character::getBounds() {
    return sprite.getGlobalBounds();
}