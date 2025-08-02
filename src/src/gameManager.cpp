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
    inp.loadFont("fonts/cursiveg.ttf");

    //fps caped
    window.create(sf::VideoMode(800, 600), "Minimal Engine", sf::Style::Default);
    window.setVerticalSyncEnabled(true);  // Optional
    window.setFramerateLimit(160); // Optional: limit to 160 FPS


    manager.create<MainText>();


}
void gameManager::pushDrawable(sf::Drawable *drawable)
{
    if (drawable)
    {
        
        drawables.push_back(drawable);
    }
}

void gameManager::mainLoop(sf::RenderWindow &window)
{
    while (window.isOpen())
    {
        inp.processInput(window);
        inp.updateTime();

        if (inp.isKeyPressed(sf::Keyboard::Escape))
            window.close();

        window.clear(sf::Color::Black);

        manager.updateAll();         // updates all game objects
        manager.drawAll(window);     // draws all game objects

        window.display();
    }
}