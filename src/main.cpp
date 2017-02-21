/**
 * vsAliens
 * main.cpp
 *
 * Main function implementation
 */

#include "../include/shared.h"
#include "../include/functional.h"

int main() {
    srand(time(NULL));
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
    bullet_Arr bullets;
    /////////////////////////////////////////////////
    sf::Event event;
    sf::Clock clock;
    /////////////////////////////////////////////////
    sf::Font font;
    font.loadFromFile("arial.ttf");
    /////////////////////////////////////////////////
    // lives text field
    sf::Text lives;
    lives.setFont(font);
    lives.setString("Lives");
    lives.setCharacterSize(24);
    lives.setColor(sf::Color::Red);

    float deltaTime = 0;

    window.setKeyRepeatEnabled(false);

    /////////////////////////////////////////////////
    // Game mainloop
    while (window.isOpen()) {
        functional::handleEvents(event, window, ship, bullets, clock, deltaTime);
        functional::checkCollisions(ship, enemies, bullets);
        ship.updatePos(deltaTime);
        functional::bulletsUpdate(bullets, deltaTime);
        functional::enemiesUpdate(enemies, deltaTime);

        deltaTime = clock.restart().asSeconds();

        functional::drawScreen(window, ship, enemies, bullets, lives);
    }

    return 0;
}
