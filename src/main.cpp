/**
 * vsAliens
 * main.cpp
 *
 * Main function implementation
 */

#include "../include/shared.h"
#include "../include/functional.h"


int main() {
    /////////////////////////////////////////////////
    // random seed
    srand((unsigned int) time(0));

    /////////////////////////////////////////////////
    // Game window
    sf::RenderWindow window(sf::VideoMode(settings::window::WIDTH,
                            settings::window::HEIGHT, 32), "vsAliens",
                            sf::Style::Titlebar);

    /////////////////////////////////////////////////
    // New ship object
    settings::textures::shipTexture.loadFromFile("images/ship.bmp");
    Ship ship(settings::textures::shipTexture);

    /////////////////////////////////////////////////
    // Enemies
    sf::Texture enemyTexture;
    settings::textures::enemyTexture.loadFromFile("images/alien.bmp");
    enemies_Arr enemies;

    /////////////////////////////////////////////////
    // vector-type container for visible bullets fired by player
    bullets_Arr bullets;

    /////////////////////////////////////////////////
    // vector-type container for bonuses
    bonuses_Arr bonuses;

    /////////////////////////////////////////////////
    // ingame events and clock
    sf::Event event;
    sf::Clock clock;

    /////////////////////////////////////////////////
    // main font
    sf::Font font;
    font.loadFromFile("arial.ttf");

    Hud hud(font);

    float deltaTime = 0;
    window.setKeyRepeatEnabled(false);

    // Game mainloop
    while (window.isOpen()) {
        functional::handleEvents(event, window, hud, ship, bullets, clock, deltaTime);
        functional::handleCollisions(hud, ship, enemies, bullets, bonuses);
        ship.updateCannonStatus();

        if (hud.getGameStatus()) { // game is active
            ship.updatePos(deltaTime);
            bullets.update(deltaTime);
            enemies.update(ship, deltaTime);
            bonuses.update();
            hud.update(ship);
        }

        deltaTime = clock.restart().asSeconds();
        functional::drawScreen(window, hud, ship, enemies, bullets, bonuses);
    }
    return 0;
}
