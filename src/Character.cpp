//
// Created by marcin on 15.01.17.
//

#include "../include/shared.h"
#include "../include/functional.h"

Character::Character(const sf::Texture& texture, float x, float y)
{
    sprite.setTexture(texture);
    sprite.setOrigin(x, y);
}

void
Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

void
Character::moveMe(Dir dir, float& delta)
{
    switch(dir)
    {
        case left:
            sprite.move(-matchSpeed() * delta, 0);
            this->setMoveFlag(Character::left, true);
            break;
        case right:
            sprite.move(matchSpeed() * delta, 0);
            this->setMoveFlag(Character::right, true);
            break;
        case down:
            sprite.move(0, matchSpeed() * delta);
            this->setMoveFlag(Character::down, true);
            break;
        case up:
            sprite.move(0, -matchSpeed() * delta);
            this->setMoveFlag(Character::up, true);
            break;
    }
}

sf::Vector2f
Character::getPosition()
{
    return sprite.getPosition();
}

void
Character::setMoveFlag(Dir flag, bool isMoving)
{
    switch(flag)
    {
        case right:
            this->isMovingRight = isMoving;
            break;
        case left:
            this->isMovingLeft = isMoving;
            break;
        case up:
            this->isMovingUp = isMoving;
            break;
        case down:
            this->isMovingDown = isMoving;
            break;
    }
}

float
Character::matchSpeed()
{
    using std::sqrt;

    if (this->isMovingRight || this->isMovingLeft)
    {
        if (this->isMovingDown || this->isMovingUp)
            return float((functional::OBJ_SPEED * sqrt(2)) / 2);
    }
    else
    {
        return functional::OBJ_SPEED;
    }

    if (this->isMovingUp || this->isMovingDown)
    {
        if (this->isMovingRight || this->isMovingLeft)
            return float((functional::OBJ_SPEED * sqrt(2)) / 2);
    }
    else
    {
        return functional::OBJ_SPEED;
    }

    return 0; //if sth went wrong just dont change its place
}

void
Character::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}