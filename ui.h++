#ifndef UI_H // UI_H header guard
#define UI_H

#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

#include <vector>

class UI : public sf::Drawable {
    public:
        UI(); // Default Contructor
        void setPosition(const sf::Vector2f &position);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void loadFont();
        void fillStatsUI();

    private:
        sf::Transformable mTransform;
        sf::Font mFont;
//        sf::Text mText;
//        sf::CircleShape mStatIcon;
        std::vector<sf::Text> mStatTexts;
        std::vector<sf::CircleShape> mStatIcons;
};

#endif // UI_H header guard