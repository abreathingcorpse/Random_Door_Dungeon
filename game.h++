#ifndef GAME_H // GAME_H header guard
#define GAME_H
#include "textConfig.h++"

class Game {
    public:
        Game(); // Default Constructor

        void run(); // Public method

    private:
        // Private methods
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
        void preConfigureText();

        // Private members
        sf::RenderWindow mWindow;
        sf::RectangleShape mDoor;
        sf::View mView;
        sf::Font mFont;
        sf::Text mText;
//        TextConfig mtextConfig;
};

#endif // GAME_H header guard