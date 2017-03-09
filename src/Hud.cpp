#include "../include/Hud.h"


Hud::Hud(sf::Font& font) {
    /////////////////////////////////////////////////
    // score text field
    score.setFont(font);
    score.setCharacterSize(24);
    score.setFillColor(sf::Color::Black);

    /////////////////////////////////////////////////
    // lives text field
    lives.setFont(font);
    lives.setCharacterSize(24);
    lives.setFillColor(sf::Color::Black);
    lives.setPosition(settings::window::WIDTH - 100, 0);
    lives.setString("[SPACE]");
    /////////////////////////////////////////////////
    // avBullets text field
    avBullets.setFont(font);
    avBullets.setCharacterSize(24);
    avBullets.setFillColor(sf::Color::Black);
    avBullets.setPosition(settings::window::WIDTH / 2 - 50, 0);
}

void
Hud::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(score, states);
    target.draw(avBullets, states);
    target.draw(lives, states);
}

void
Hud::update() {
    std::string scoreMsg = "Score: " + std::to_string(stats::game::score);
    score.setString(scoreMsg);

    std::string livesMsg = "Lives: " + std::to_string(stats::game::lives);
    lives.setString(livesMsg);

    std::string avBulletsMsg;

    for (int i = 0; i < stats::bullet::bulletsLeft; ++i) {
        avBulletsMsg += "* ";
    }

    for (int i = 0; i < stats::bullet::maxBullets - stats::bullet::bulletsLeft; ++i) {
        avBulletsMsg +=  "- ";
    }

    avBullets.setString(avBulletsMsg);
}

void
Hud::gameOver() {
    score.setString("");
    avBullets.setString("");
    lives.setString(":(((");
}
