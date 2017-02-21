//
// Created by marcin on 06.02.17.
//

#pragma once

#include "../include/shared.h"

class Button : public sf::Drawable {
public:
    Button(const sf::Font& font, float x, float y);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::Sprite sprite;
};
