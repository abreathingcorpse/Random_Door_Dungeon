#ifndef UI_H // UI_H header guard
#define UI_H

#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

class UI : public sf::Drawable {
    public:
        UI(); // Default Contructor
        void setPosition(const sf::Vector2f &position);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void loadFont();
        void preConfigureText();

    private:
        sf::Transformable mTransform;
        sf::Font mFont;
        sf::Text mText;
};

#endif // UI_H header guard