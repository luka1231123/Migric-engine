/// @file gameManager.cpp
/// @brief Implementation of the minimal game engine controller.

#include "gameManager.hpp"

void gameManager::run()
{
    sf::RenderWindow window;
    init(window);
    mainLoop(window);
}

void gameManager::init(sf::RenderWindow &window)
{
    // initialize font
    sf::Font font;
    if (!font.loadFromFile("fonts/cursiveg.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }

    //fps caped
    window.create(sf::VideoMode(800, 600), "Minimal Engine", sf::Style::Default);
    window.setVerticalSyncEnabled(true);  // Optional
    window.setFramerateLimit(160); // Optional: limit to 160 FPS


}

void gameManager::mainLoop(sf::RenderWindow &window)
{
    while (window.isOpen())
    {
        inp.processInput(window);
        inp.updateTime();
        
        if (inp.isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        //std::cout << "FPS: " << inp.getFPS() << std::endl;
        window.clear();


        window.display();

    }
}