#ifndef DOOR_H // DOOR_H header guard
#define DOOR_H

#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

class Door : public sf::RectangleShape {

    public:
        Door(); // Default Constructor
        // Other Constructors
        Door(sf::Vector2f DoorDimensions, sf::Vector2f DoorPosition);
        Door(sf::Vector2f DoorDimensions, sf::Vector2f DoorPosition,
            sf::Color DoorColor);

        // Public methods
//        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void loadClubSprite();

        // Public members
        sf::Vector2f mDoorDimensions;
        sf::Vector2f mDoorPosition;
        sf::Color mDoorColor;

        // Define the 4 door types
//        static const Door Red;
//        static const Door Green;
//        static const Door Blue;
//        static const Door Gray;
        std::vector<sf::Color> mAvailableDoorColors = {sf::Color::Red,
                                                        sf::Color::Green,
                                                        sf::Color::Blue,
                                                        sf::Color::White};

//        sf::Transformable mTransform;
        sf::Sprite mWeaponSprite;

    private:
        std::string mClubTexturePath = "resources/art/Club.png";
        sf::Texture mClubTexture;
};

#endif // DOOR_G header guard