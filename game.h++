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

Game::Game() : mWindow(sf::VideoMode(640,480),
                       "Random Door Dungeon"),
               mDoor() {
                mDoor.setSize(sf::Vector2f(50,100));
                mDoor.setFillColor(sf::Color::Red);
                mDoor.setPosition(100,100);
               }

void Game::processEvents() {
    sf::Event event;

    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Game::update(sf::Time deltaTime) {
    // Such emptiness
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mDoor);
    mWindow.display();
}

void Game::run() {
    sf::Clock clock;
    sf::Time elapsedTime;
    const sf::Time framerate = sf::seconds(1.f/60); // .f forces it to be a float, so that it's not 0

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