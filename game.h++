#ifndef GAME_H // GAME_H header guard
#define GAME_H

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
        sf::RectangleShape mDoor;
        sf::View mView;
        sf::Font mFont;
        sf::Text mText;
        int mDoorWidth = 130;
        int mDoorHeight = 180;
        int mDoorX = 460;
        int mDoorY = 460;
};

#endif // GAME_H header guard