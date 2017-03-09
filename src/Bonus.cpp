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
        case extra_bullet :
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
Bonus::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

sf::FloatRect
Bonus::getBounds() {
    return sprite.getGlobalBounds();
}

float
Bonus::getSpawnTime() {
    float spawnTime = spawnClock.getElapsedTime().asSeconds();
    return spawnTime;
}

//////////////////////////////////////////////////////////////////////////////

void
bonuses_Arr::spawn() {
    if (stats::enemy::fragCounter >= 5) {
        Bonus newBonus(stats::enemy::lastPos.x,
                       stats::enemy::lastPos.y,
                       static_cast<Bonus::Type>(rand() % 3));
        push_back(newBonus);
        stats::enemy::fragCounter = 0;
    }
}

void
bonuses_Arr::update() {
    spawn();

    for (unsigned int i = 0; i < size(); ++i) {
        if (at(i).getSpawnTime() > 5) {
            erase(begin() + i);
        }
    }
}
