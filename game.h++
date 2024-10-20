#ifndef GAME_H // GAME_H header guard
#define GAME_H
#include "door.h++"
#include "ui.h++"
#include <vector>
#include <unordered_set>

class Game {
    public:
        Game(); // Default Constructor

        void run(); // Public method

    private:
        // Private methods
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
//        void preConfigureText();
        void resizeToAspectRatio(float desired_aspect_ratio, float current_aspect_ratio);
        void initializeDoors();
        void generate_random_doors();

        // Private members
        sf::RenderWindow mWindow;
//        Door mDoor;
        std::vector<Door> mDoors;
        sf::View mView;
        sf::Font mFont;
        sf::Text mText;
        sf::Vector2i mMousePosition;
        sf::Vector2f mMouseViewPosition;
        int mSpaceBetweenDoors = 300;
        UI mUI;
        std::unordered_set<unsigned int> mDoorTypeIndexes;
//        sf::Texture mClubTexture;
//        sf::Sprite mClubSprite;
};

#endif // GAME_H header guard