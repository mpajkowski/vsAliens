//
// Created by marcin on 18.01.17.
//

#pragma once

#include "../include/shared.h"

class Bullet : public sf::Drawable {
public:
    Bullet(sf::Vector2f pos);

    virtual void draw(sf::RenderTarget& target,
                      sf::RenderStates states) const;

    sf::Vector2f getPos();

    void updateBullet(float& deltaTime);

    sf::Sprite getSprite();

    sf::FloatRect getBounds();

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f pos;
};

class bullets_Arr : public ObjectContainer<Bullet> {
public:
    void update(float& deltaTime);
};
