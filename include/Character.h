//
// Created by marcin on 15.01.17.
//

#ifndef VSALIENS_CHARACTER_H
#define VSALIENS_CHARACTER_H
#include "../include/shared.h"

class Character : public sf::Drawable
{
private:
    sf::Sprite sprite;
    bool isMovingLeft = false;
    bool isMovingRight = false;
    bool isMovingUp = false;
    bool isMovingDown = false;
    float matchSpeed();

public:
    enum Dir { right, left, up, down };
    Character(const sf::Texture& texture, float x, float y);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    void setMoveFlag(Dir flag, bool value);
    void moveMe(Dir dir, float& delta);
};
#endif //VSALIENS_CHARACTER_H
