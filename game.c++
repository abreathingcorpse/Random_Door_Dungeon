#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

#include "game.h++"
#include "door.h++"
#include "ui.h++"
#include <iostream>
#include <string>
#include <random>
#include <time.h>

Game::Game() : //mWindow(sf::VideoMode(1920,1080), "Random Door Dungeon", sf::Style::Fullscreen),
    mWindow(sf::VideoMode(1920,1080),
           "Random Door Dungeon"),
//   mDoor(sf::Vector2f(130.f,180.f), sf::Vector2f(0,0), sf::Color::Red),
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

void Game::initializeDoors() {

    auto DoorTypeSetIterator = mDoorTypeIndexes.cbegin();

    // Create the doors, set positions and colors
    for (int i = 0; i < 3; i++) {

        sf::Vector2f doorPosition(580.f + i * mSpaceBetweenDoors,460.f);
        Door aDoor = Door(sf::Vector2f(130.f,180.f), doorPosition);
        
        if (DoorTypeSetIterator == mDoorTypeIndexes.cend()) {
            std::cerr << "DoorTypeSetIterator out of bounds." << std::endl;
        }

        sf::Color doorColor = aDoor.mAvailableDoorColors[*DoorTypeSetIterator];
        aDoor.setFillColor(doorColor);

//        if(*DoorTypeSetIterator == 0) {
//            aDoor.loadClubSprite();
//        }
        aDoor.mWeaponSprite.setPosition(610.f + i * mSpaceBetweenDoors, 510.f);
        mDoors.push_back(aDoor);

//        if(*DoorTypeSetIterator == 0) {
//            mDoors[i].loadClubSprite();
//        }

        DoorTypeSetIterator++;
    }

    // Load respective weapon sprite
    DoorTypeSetIterator = mDoorTypeIndexes.cbegin();
    for (int i = 0; i < 3; i++) {
        if (DoorTypeSetIterator == mDoorTypeIndexes.cend()) {
            std::cerr << "DoorTypeSetIterator out of bounds." << std::endl;
        }

        if(*DoorTypeSetIterator == 0) {
            mDoors[i].loadClubSprite();
        } else if (*DoorTypeSetIterator == 1) {
            mDoors[i].loadBowSprite();
        } else if (*DoorTypeSetIterator == 2) {
            mDoors[i].loadSpellbookSprite();
        } else if (*DoorTypeSetIterator == 3) {
            mDoors[i].loadKnifeSprite();
        }

        DoorTypeSetIterator++;
    }
}

void Game::generate_random_doors() {
    std::mt19937 random_engine(std::time(0));
    // Original
    std::uniform_int_distribution<unsigned int> uniform_distribution(0,3);

    while (mDoorTypeIndexes.size() < 3) {
        mDoorTypeIndexes.insert(uniform_distribution(random_engine));
    }

    // iterate over the set, for printing purposes
//    auto set_it = door_type_indexes.cbegin();
//    while (set_it != door_type_indexes.cend()) {
//        std::cout << *set_it << std::endl;
//        ++set_it;
//    }
}

std::pair<bool, int> Game::mouseInsideDoor() {
    for (decltype(mDoors.size()) i=0; i < mDoors.size(); i++) {
         if (
            (mMouseViewPosition.x > mDoors[i].mDoorPosition.x &&
            mMouseViewPosition.x < mDoors[i].mDoorPosition.x + mDoors[i].mDoorDimensions.x) &&
            (mMouseViewPosition.y > mDoors[i].mDoorPosition.y &&
            mMouseViewPosition.y < mDoors[i].mDoorPosition.y + mDoors[i].mDoorDimensions.y)
        ) {
            return std::make_pair(true,i);
        }
    }
    // Default, whenever the mouse wasn't within a door
    return std::make_pair(false,0);
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

        // Check if a door is being hovered on
        if (event.type == sf::Event::MouseMoved) {
            std::pair<bool, int> mouseInsideDoorPair = mouseInsideDoor();
            if (mouseInsideDoorPair.first)
                        mDoors[mouseInsideDoorPair.second].setFillColor(sf::Color::Red);
        }
        // Check if a door was clicked on
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            std::pair<bool, int> mouseInsideDoorPair = mouseInsideDoor();
            if (mouseInsideDoorPair.first)
                        mDoors[mouseInsideDoorPair.second].setFillColor(sf::Color::Green);
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
    auto numberOfDoors = mDoors.size(); // numberOfDoors has a weird size type
    decltype(mDoors.size()) currentDoorIndex = 0; // currentDoorIndex share the same weird size type

    while (currentDoorIndex < numberOfDoors){
        mWindow.draw(mDoors[currentDoorIndex]);
        mWindow.draw(mDoors[currentDoorIndex].mWeaponSprite);
        currentDoorIndex++;
    }

    mWindow.draw(mUI);
    mWindow.display();
}

void Game::run() {
    sf::Clock clock;
    sf::Time elapsedTime;
    const sf::Time framerate = sf::seconds(1.f/60); // .f forces it to be a float, so that it's not 0
    generate_random_doors();
    initializeDoors();
//    mUI.setPosition(sf::Vector2f(200.f,200.f)); // Tested that when the position of UI changes, all of the child change as well

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