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

        // Private members
        sf::RenderWindow mWindow;
        sf::RectangleShape mDoor;
};

#endif // GAME_H header guard