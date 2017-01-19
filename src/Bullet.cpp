//
// Created by marcin on 18.01.17.
//

#include "../include/shared.h"
#include "../include/Bullet.h"

Bullet::Bullet(Ship* ship)
{
    if(!texture.loadFromFile("images/bullet.bmp"))
    {
        std::cout << "kurwa mac" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(2, 8);
    sprite.setColor(sf::Color::Black);

    pos.x = ship->getPosition().x;
    pos.y = ship->getPosition().y;
    sprite.setPosition(pos);
}

Bullet::~Bullet()
{

}

void
Bullet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

sf::Vector2f
Bullet::getPos()
{
    return pos;
}