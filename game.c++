#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

#include "game.h++"
#include "door.h++"
#include <iostream>
#include <string>

Game::Game() : //mWindow(sf::VideoMode(1920,1080), "Random Door Dungeon", sf::Style::Fullscreen),
    mWindow(sf::VideoMode(1920,1080),
           "Random Door Dungeon"),
   mDoor(sf::Vector2f(130.f,180.f), sf::Vector2f(0,0), sf::Color::Red),
   mView(sf::FloatRect(0.f, 0.f, 1920.f, 1080.f)),
   mFont(),
   mText()
   { }

void Game::resizeToAspectRatio(float desired_aspect_ratio, float current_aspect_ratio) {
    if (current_aspect_ratio > desired_aspect_ratio) {
        mView.setViewport(sf::FloatRect((1 - desired_aspect_ratio/current_aspect_ratio) /
                                        2.f, 0.f, desired_aspect_ratio/current_aspect_ratio, 1.f));
    } else if (current_aspect_ratio < desired_aspect_ratio) {
        mView.setViewport(sf::FloatRect(0.f, (1 - current_aspect_ratio/desired_aspect_ratio) /
                                        2.f, 1.f, current_aspect_ratio/desired_aspect_ratio));
    } else {
        mView.setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));
    }
}


void Game::processEvents() {
    sf::Event event;

    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();
        if (event.type == sf::Event::Resized) {
//            std::cout << "(" << event.size.width << ","
//                      << event.size.height << ")" << std::endl;
            // Hardcoded desired aspect ratio. This could be chosen by the user in the future.
            float desired_aspect_ratio = 1920.f / 1080.f;
            float current_aspect_ratio = static_cast<float>(event.size.width) / static_cast<float>(event.size.height);

//            std::cout << "current ratio: " << current_aspect_ratio << std::endl;
            resizeToAspectRatio(desired_aspect_ratio, current_aspect_ratio);
        }

        // Resize the Door Dimensions
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
//            mDoorHeight += 10;
//            std::cout << "Current Door dimensions: (" << mDoorWidth << "," << mDoorHeight << ")" << std::endl;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
//            mDoorHeight -= 10;
//            std::cout << "Current Door dimensions: (" << mDoorWidth << "," << mDoorHeight << ")" << std::endl;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
//            mDoorWidth -= 10;
//            std::cout << "Current Door dimensions: (" << mDoorWidth << "," << mDoorHeight << ")" << std::endl;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
//            mDoorWidth += 10;
//            std::cout << "Current Door dimensions: (" << mDoorWidth << "," << mDoorHeight << ")" << std::endl;
//        }

        // Update the Door position
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
//            mDoorY -= 10;
//            std::cout << "Current Door position: (" << mDoorX << "," << mDoorY << ")" << std::endl;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
//            mDoorX -= 10;
//            std::cout << "Current Door position: (" << mDoorX << "," << mDoorY << ")" << std::endl;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
//            mDoorY += 10;
//            std::cout << "Current Door postion: (" << mDoorX << "," << mDoorY << ")" << std::endl;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
//            mDoorX += 10;
//            std::cout << "Current Door position: (" << mDoorX << "," << mDoorY << ")" << std::endl;
//        }
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
//            std::cout << "Mouse position relative to the window: (" << mMousePosition.x << "," << mMousePosition.y << ")" << std::endl;
//            std::cout << "Mouse position relative to the view: (" << mMouseViewPosition.x << "," << mMouseViewPosition.y << ")" << std::endl;
//        }

        // Check if a door was clicked on
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//            for (int i=0; i<3; i++) {
//                int doorX0 = mDoorX + i * (mDoorWidth + mSpaceBetweenDoors);
//                int doorX1 = mDoorX + mDoorWidth + i * (mDoorWidth + mSpaceBetweenDoors);
//                std::cout << "doorX0: " << doorX0 << "," << "doorX1: " << doorX1 << std::endl;
                if (
                    (mMouseViewPosition.x > mDoor.mDoorPosition.x &&
                    mMouseViewPosition.x < mDoor.mDoorPosition.x + mDoor.mDoorDimensions.x) &&
                    (mMouseViewPosition.y > mDoor.mDoorPosition.y &&
                    mMouseViewPosition.y < mDoor.mDoorPosition.y + mDoor.mDoorDimensions.y)
                ) {
                        mDoor.setFillColor(sf::Color::Green);
                }
//            }
        }
    }
}

void Game::update(sf::Time deltaTime) {
//    mDoor.setSize(sf::Vector2f(mDoorWidth,mDoorHeight));
//    mDoor.setSize(sf::Vector2f(mDoor.mDoorDimensions.x,mDoor.mDoorDimensions.y));
//    mDoor.setPosition(mDoorX,mDoorY);
//    mDoor.setPosition(mDoor.mDoorPosition.x,mDoor.mDoorPosition.y);
    mMousePosition = sf::Mouse::getPosition(mWindow);
    mMouseViewPosition = mWindow.mapPixelToCoords(mMousePosition,mView);
}

void Game::render() {
    mWindow.clear();
    mWindow.setView(mView);
    // Drawing a lightgray rectangle as a map
    sf::RectangleShape map(sf::Vector2f (1920.f, 1080.f));
    map.setFillColor(sf::Color(185,184,181));
    mWindow.draw(map);
    // Render all three doors
//    for (int i=0; i<3; i++) {
//       mDoor.setPosition(mDoorX + i * (mDoorWidth + mSpaceBetweenDoors), mDoorY);
        mWindow.draw(mDoor);
//   }
    mWindow.draw(mText);
    mWindow.display();
}

void Game::preConfigureText() {
    std::string pathToFontFile = "./resources/fonts/NotoSans-Regular.ttf";
    if(!mFont.loadFromFile(pathToFontFile)) {
        std::cout << "Unable to load the font." << std::endl;
    }
    mText.setFont(mFont);
    mText.setString("Str: ");
    mText.setCharacterSize(24);
    mText.setFillColor(sf::Color::White);
}

void Game::run() {
    sf::Clock clock;
    sf::Time elapsedTime;
    const sf::Time framerate = sf::seconds(1.f/60); // .f forces it to be a float, so that it's not 0
    preConfigureText();

    while(mWindow.isOpen()){
        elapsedTime += clock.restart();
        while (elapsedTime > framerate) {
            elapsedTime -= framerate;
            processEvents();
            update(elapsedTime);
        }
        render();
    }
}