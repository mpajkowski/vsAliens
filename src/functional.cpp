//
// Created by marcin on 15.01.17.
//
#include "../include/shared.h"
#include "../include/functional.h"


void
functional::handleEvents(sf::Event& event, sf::Clock& clock,
                         sf::RenderWindow& window, Ship* ship,
                         bullet_Arr& bullets)
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed :
                if (ship != NULL)
                    delete ship;
                window.close();
                break;
            case sf::Event::KeyPressed :
                if (event.key.code == sf::Keyboard::Space)
                    fireBullet(ship, bullets);
                break;
        }
    }

    float deltaTime = clock.restart().asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //move up
    {
        ship->moveMe(Character::up, deltaTime);
    }
    else
    {
        ship->setMoveFlag(Character::up, false);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //move down
    {
        ship->moveMe(Character::down, deltaTime);
    }
    else
    {
        ship->setMoveFlag(Character::down, false);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //move right
    {
        ship->moveMe(Character::right, deltaTime);
    }
    else
    {
        ship->setMoveFlag(Character::right, false);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //move left
    {
        ship->moveMe(Character::left, deltaTime);
    }
    else
    {
        ship->setMoveFlag(Character::left, false);
    }
    float timeFired;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        window.close();
    }
}

void
functional::fireBullet(Ship* ship, bullet_Arr& bullets)
{
    Bullet newBullet(ship);
    bullets.push_back(newBullet);
    std::cout << "New bullet: " << bullets.back().getPos().x
              << "x" << bullets.back().getPos().y << std::endl;
}