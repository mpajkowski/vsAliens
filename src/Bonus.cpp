#include "../include/shared.h"
#include "../include/Bonus.h"

Bonus::Bonus(sf::Vector2f pos, Type type)
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

    sprite.setPosition(pos);
}

void
Bonus::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

sf::FloatRect
Bonus::getBounds()
{
    return sprite.getGlobalBounds();
}

float
Bonus::getSpawnTime()
{
    float spawnTime = spawnClock.getElapsedTime().asSeconds();
    return spawnTime;
}

void
Bonus::handleAction(Type type, Ship& ship, enemies_Arr& enemies)
{
    switch (type) {
        case extra_life :
            break;
        case super_bullet :
            break;
        case extra_bullet :
            break;
        default :
            break;
    }
}
//////////////////////////////////////////////////////////////////////////////


bonuses_Arr::bonuses_Arr()
{
    resetFragCounter();
}

void
bonuses_Arr::spawn()
{
    if (getFragCounter() >= 5) {
        Bonus newBonus(pos, static_cast<Bonus::Type>(rand() % Bonus::max));
        push_back(newBonus);
        resetFragCounter();
    }
}

void
bonuses_Arr::update()
{
    spawn();

    for (uint i = 0; i < size(); ++i) {
        if (at(i).getSpawnTime() > 5) {
            erase(begin() + i);
        }
    }
}

void
bonuses_Arr::updatePos(sf::Vector2f newPos)
{
    this->pos = newPos;
}

void
bonuses_Arr::updateFragCounter(int arg)
{
    this->fragCounter += arg;
}

void
bonuses_Arr::resetFragCounter()
{
    fragCounter = 0;
}

int
bonuses_Arr::getFragCounter()
{
    return fragCounter;
}
