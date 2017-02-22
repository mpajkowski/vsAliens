/**
 * vsAliens
 * main.cpp
 *
 * Main function implementation
 */

#include "../include/shared.h"
#include "../include/functional.h"
#include "../include/stats.h"

int main() {
    /////////////////////////////////////////////////
    // random seed
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

    /////////////////////////////////////////////////
    // score text field
    sf::Text score;
    score.setFont(font);
    score.setCharacterSize(24);
    score.setFillColor(sf::Color::Black);

    /////////////////////////////////////////////////
    // lives text field
    sf::Text lives;
    lives.setFont(font);
    lives.setCharacterSize(24);
    lives.setFillColor(sf::Color::Black);
    lives.setPosition(settings::window::WIDTH - 300, 0);
    lives.setString("Press SPACE to start");

    /////////////////////////////////////////////////
    float deltaTime = 0;

    window.setKeyRepeatEnabled(false);

    /////////////////////////////////////////////////
    // Game mainloop
    while (window.isOpen()) {
        functional::handleEvents(event, window, ship, bullets, lives, clock, deltaTime);
        functional::checkCollisions(ship, enemies, bullets, bonuses, lives);

        if (stats::game::isActive) {
            ship.updatePos(deltaTime);
            functional::bulletsUpdate(bullets, deltaTime);
            functional::enemiesUpdate(enemies, deltaTime);
            functional::spawnBonuses(bonuses);
            functional::updateScore(score);
            functional::updateLives(lives);
        }

        deltaTime = clock.restart().asSeconds();

        functional::drawScreen(window, ship, enemies, bullets, bonuses, score, lives);
    }

    return 0;
}
