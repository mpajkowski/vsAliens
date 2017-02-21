//
// Created by marcin on 15.01.17.
//

#pragma once

#include "../include/shared.h"

class Character : public sf::Drawable {
public:
    enum Dir {
        right, left, up, down
    };

    Character(const sf::Texture& texture, float x, float y, float speed);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void setPosition(float x, float y);

    sf::Vector2f getPosition();

    void setMoveFlag(Dir dir, bool value);

    bool getMoveFlag(Dir dir);

    sf::Sprite getSprite();

    sf::FloatRect getBounds();

    void updatePos(float& delta);

protected:
    bool canMove(Dir dir);

    void confirmMove();

private:
    sf::Sprite sprite;
    bool isMovingLeft = false;
    bool isMovingRight = false;
    bool isMovingUp = false;
    bool isMovingDown = false;
    float speed;

    float matchSpeed();
};