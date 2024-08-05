#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

#include "ui.h++"
#include <iostream>

// Constructor Initializer List
UI::UI() : mTransform(), mFont(), mText() {
    loadFont();
//    mText(": 1", mFont);
}

void UI::setPosition(const sf::Vector2f &position) {
    mTransform.setPosition(position);
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const {
    target.draw(mText,mTransform.getTransform());
}

void UI::loadFont() {
    std::string pathToFontFile = "./resources/fonts/NotoSans-Regular.ttf";
    if(!mFont.loadFromFile(pathToFontFile)) {
        std::cout << "Unable to load the font." << std::endl;
    }
}

void UI::preConfigureText() {
    mText.setFont(mFont);
    mText.setString("Str: ");
    mText.setCharacterSize(24);
    mText.setFillColor(sf::Color::White);
}
