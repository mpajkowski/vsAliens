//
// Created by marcin on 18.01.17.
//

#ifndef VSALIENS_BULLET_H
#define VSALIENS_BULLET_H

#include "../include/shared.h"
#include "../include/Ship.h"


class Bullet : public sf::Drawable
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f pos;

public:
    Bullet(Ship* ship);
    ~Bullet();

    virtual void draw(sf::RenderTarget& target,
                      sf::RenderStates states) const;
    sf::Vector2f getPos();
};

typedef std::vector<Bullet> bullet_Arr;
#endif //VSALIENS_BULLET_H
