#pragma once

#include "shared.h"

class Hud : public sf::Drawable {
public:
    Hud(sf::Font& font);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    void gameOver();
private:
    sf::Text score;
    sf::Text avBullets;
    sf::Text lives;
};
