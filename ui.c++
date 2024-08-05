#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

#include "ui.h++"
#include <iostream>

// Constructor Initializer List
UI::UI() : mTransform(), mFont(), mStatTexts(), mStatIcons() {
    loadFont();
    fillStatsUI();
//    mStatIcon.setFillColor(sf::Color::Red);
}

void UI::setPosition(const sf::Vector2f &position) {
    mTransform.setPosition(position);
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const {
    for (decltype(mStatTexts.size()) i = 0; i < mStatTexts.size(); i++) {
        target.draw(mStatTexts[i],mTransform.getTransform());
        target.draw(mStatIcons[i],mTransform.getTransform());
    }
//    target.draw(mStatIcon,mTransform.getTransform());
}

void UI::loadFont() {
    std::string pathToFontFile = "./resources/fonts/NotoSans-Regular.ttf";
    if(!mFont.loadFromFile(pathToFontFile)) {
        std::cout << "Unable to load the font." << std::endl;
    }
}

void UI::fillStatsUI() {
    for (int i = 0; i <= 3; i++) {
        sf::Text currentStatText(": 1", mFont); // CharacterSize = 30 by default
        currentStatText.setFillColor(sf::Color::White);
        currentStatText.setPosition(sf::Vector2f(30.f, i * 40.f));
        mStatTexts.push_back(currentStatText);

        sf::CircleShape currentStatIcon(10);
        currentStatIcon.setPosition(sf::Vector2f(5.f, 10.f + i * 40.f));
        mStatIcons.push_back(currentStatIcon);
    }

    mStatIcons[0].setFillColor(sf::Color::Red);
    mStatIcons[1].setFillColor(sf::Color::Green);
    mStatIcons[2].setFillColor(sf::Color::Blue);
    mStatIcons[3].setFillColor(sf::Color::White);
}
