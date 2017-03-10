//
// Created by marcin on 18.01.17.
//

#include "../include/shared.h"
#include "../include/Bullet.h"

Bullet::Bullet(sf::Vector2f pos) {
    texture.loadFromFile("images/bullet.bmp");

    sprite.setTexture(texture);
    sprite.setOrigin(2, 8);
    sprite.setColor(sf::Color::Black);

    pos.y -= 20;

    sprite.setPosition(pos);
}

void
Bullet::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

sf::Vector2f
Bullet::getPos() {
    return sprite.getPosition();
}

void
Bullet::updateBullet(float& deltaTime) {
    sprite.move(0, -stats::bullet::speed * deltaTime);
}

sf::FloatRect
Bullet::getBounds() {
    return sprite.getGlobalBounds();
}

////////////////////////////////////////////////////////////////////////

void
bullets_Arr::update(float& deltaTime) {
    for (unsigned int i = 0; i < size(); ++i) {
        at(i).updateBullet(deltaTime);

        if (at(i).getPos().y < 0) {
            erase(begin() + i);
        }
    }
}
