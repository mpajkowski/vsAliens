#include "../include/shared.h"
#include "../include/Bonus.h"

Bonus::Bonus(float x, float y)
{
    texture.loadFromFile("images/bonus.bmp");

    sprite.setTexture(texture);
    sprite.setOrigin(2.5, 2.5);
    sprite.setColor(sf::Color::Black);

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
