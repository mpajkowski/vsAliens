//
// Created by marcin on 06.02.17.
//

#include "../include/Button.h"

Button::Button(const sf::Font& font, float x, float y) {
    sprite.setPosition(x, y);
}

void
Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void
Button::setText(std::string text) {

}
