#include <iostream>// test
#include "../include/shared.h"
#include "../include/functional.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 768, 32), "vsAliens");
    /////////////////////////////////////////////////
    sf::Texture shipTexture;                   //////
    shipTexture.loadFromFile("images/ship.bmp"); ////
                                                /////
    Ship* ship = new Ship(shipTexture);        //////
    /////////////////////////////////////////////////

    bullet_Arr bullets;
    sf::Event event;
    sf::Clock clock;

    while(window.isOpen())
    {
        functional::handleEvents(event, clock, window, ship, bullets);

        window.clear(sf::Color::White);
        window.draw(*ship);

        for (int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        /* std::cout << ship->getPosition().x <<
                "x" << ship->getPosition().y <<
                std::endl; */
        window.display();
    }

    //delete ship;
    delete ship;

    return 0;
}