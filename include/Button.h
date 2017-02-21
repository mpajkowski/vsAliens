//
// Created by marcin on 06.02.17.
//

#pragma once

#include "../include/shared.h"

class Button : public sf::Drawable {
public:
    Button(const sf::Font& font, float x, float y);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setText(std::string text);
private:
    sf::Text text;
    sf::Font font;
    sf::Sprite sprite;
};
