#ifndef DOOR_H // DOOR_H header guard
#define DOOR_H

#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

class Door : public sf::RectangleShape {

    public:
        Door(); // Default Constructor
        sf::Vector2f mDoorDimensions;
        sf::Vector2f mDoorPosition;

    private:
//        sf::Vector2i mDoorDimensions;
//        mDoorDimensions.x = 130;
//        mDoorDimensions.y = 180;
//        sf::Vector2i mDoorDimensions(130,180);
//        sf::Vector2i mDoorPosition;
//        mDoorPosition.x = 580;
//        mDoorPosition.y = 460;
//        sf::Vector2i mDoorPosition(580,460);
};

#endif // DOOR_G header guard