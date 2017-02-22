#pragma once

#include "../include/shared.h"
#include "../include/Enemy.h"

class Bonus : public sf::Drawable {
public:
    Bonus(float x, float y);

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

typedef std::vector<Bonus> bonuses_Arr;
