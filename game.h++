class Game {
    public:
        Game(); // Default Constructor

        void run(); // Public method

    private:
        // Private methods
        void processEvents();
        void update();
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

void Game::run() {
    while(mWindow.isOpen()){
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;

    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Game::update() {
    // Such emptiness
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mDoor);
    mWindow.display();
}