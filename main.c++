#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h++"

int main () {
    Game game;

//    sf::Font font;
//    if(!font.loadFromFile("./resources/fonts/NotoSans-Regular.ttf")) {
//        std::cout << "Could not load the font" << std::endl;
//    }
//
//    sf::Text text;
//    text.setFont(font);
//    text.setString("Str: ");
//    text.setCharacterSize(24);
//    text.setFillColor(sf::Color::White);

    game.run();
}