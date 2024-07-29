#ifndef GAME_H // GAME_H header guard
#define GAME_H
#include "door.h++"

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
        void resizeToAspectRatio(float desired_aspect_ratio, float current_aspect_ratio);

        // Private members
        sf::RenderWindow mWindow;
        Door mDoor;
 //       sf::RectangleShape mDoor;
        sf::View mView;
        sf::Font mFont;
        sf::Text mText;
//        int mDoorWidth = 130;
//        int mDoorHeight = 180;
//        int mDoorX = 580;
//        int mDoorY = 460;
        sf::Vector2i mMousePosition;
        sf::Vector2f mMouseViewPosition;
        int mSpaceBetweenDoors = 200;
};

#endif // GAME_H header guard