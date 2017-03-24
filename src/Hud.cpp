#include "../include/Hud.h"


Hud::Hud(sf::Font& font)
{
    score.setFont(font);
    score.setCharacterSize(24);
    score.setFillColor(sf::Color::Black);
    score_i = 0;

    lives.setFont(font);
    lives.setCharacterSize(24);
    lives.setFillColor(sf::Color::Black);
    lives.setPosition(settings::window::WIDTH - 100, 0);
    lives.setString("[SPACE]");

    avBullets.setFont(font);
    avBullets.setCharacterSize(24);
    avBullets.setFillColor(sf::Color::Black);
    avBullets.setPosition(settings::window::WIDTH / 2 - 50, 0);
    gameStatus = false;
}

void
Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(score, states);
    target.draw(avBullets, states);
    target.draw(lives, states);
}

void
Hud::update(Ship& ship)
{
    std::string scoreMsg = "Score: " + std::to_string(score_i);
    score.setString(scoreMsg);

    std::string livesMsg = "Lives: " + std::to_string(ship.getLives());
    lives.setString(livesMsg);

    std::string avBulletsMsg;

    for (int i = 0; i < ship.getBulletsLeft(); ++i) {
        avBulletsMsg += "* ";
    }

    for (int i = 0; i < ship.getMaxBullets() - ship.getBulletsLeft(); ++i) {
        avBulletsMsg +=  "- ";
    }

    avBullets.setString(avBulletsMsg);
}

void
Hud::setGameStatus(bool isActive)
{
    this->gameStatus = isActive;
}

bool
Hud::getGameStatus()
{
    return gameStatus;
}

void
Hud::updateScore(int arg)
{
    this->score_i += arg;
}

void
Hud::gameOver()
{
    avBullets.setString("");
    lives.setString(":(((");
    score_i = 0;
}
