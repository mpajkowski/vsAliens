#pragma once

#include "shared.h"
#include "Ship.h"

class Hud : public sf::Drawable
{
public:
    Hud(sf::Font& font);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(Ship& ship);
    void gameOver();
    void updateScore(int arg);
    int getScore();
    void setGameStatus(bool isActive);
    bool getGameStatus();
private:
    sf::Text score;
    sf::Text avBullets;
    sf::Text lives;
    int score_i;
    bool gameStatus;
};
