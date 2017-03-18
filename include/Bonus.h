#pragma once

#include "../include/shared.h"
#include "../include/Enemy.h"

class Bonus : public sf::Drawable {
public:
    enum Type {
        extra_life, super_bullet, extra_bullet, max
        };

    Type type;

    Bonus(sf::Vector2f pos, Type type);

    virtual void draw(sf::RenderTarget& target,
                      sf::RenderStates states) const;

    sf::Vector2f getPos();

    void updateBullet(float& deltaTime);

    sf::Sprite getSprite();

    sf::FloatRect getBounds();

    float getSpawnTime();

    void handleAction(Type type, Ship& ship, enemies_Arr& enemies);
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f pos;
    sf::Clock spawnClock;
};

class bonuses_Arr : public ObjectContainer<Bonus> {
private:
    sf::Vector2f pos;
    int fragCounter;
public:
    void spawn();
    void update();
    void updatePos(sf::Vector2f newPos);
    void updateFragCounter(int arg);
    void resetFragCounter();
    int getFragCounter();
};
