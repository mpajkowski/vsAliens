#include "../include/shared.h"
#include "../include/Bonus.h"

Bonus::Bonus(float x, float y, Type type)
{
    texture.loadFromFile("images/bonus.bmp");

    sprite.setTexture(texture);
    sprite.setOrigin(2.5, 2.5);

    this->type = type;
    switch (type) {
        case extra_life :
            sprite.setColor(sf::Color::Blue);
            break;
        case super_bullet :
            sprite.setColor(sf::Color::Green);
            break;
        case faster_bullet :
            sprite.setColor(sf::Color::Red);
            break;
        default :
            break;
    }

    pos.x = x;
    pos.y = y;
    sprite.setPosition(pos);
}

void
Bonus::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

sf::Vector2f
Bonus::getPos()
{
    return sprite.getPosition();
}

sf::Sprite
Bonus::getSprite() {
    return sprite;
}

sf::FloatRect
Bonus::getBounds() {
    return sprite.getGlobalBounds();
}
