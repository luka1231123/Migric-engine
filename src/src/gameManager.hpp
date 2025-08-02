/// @file gameManager.hpp
/// @brief The top‑level engine class responsible for driving the game loop.
///
/// gameManager encapsulates the core functionality of the minimal
/// engine.  It creates an SFML window, runs the main loop and
/// delegates input handling to the inputManager singleton.  All
/// game‑specific logic has been removed leaving only the bare
/// essentials required to spin a window and respond to Escape.

#pragma once

#include <locale>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "inputManager.hpp"
#include "objects/objectManager.hpp"
#include "objects/mainText.hpp"

class gameManager
{
public:

    void run();

    void pushDrawable(sf::Drawable *drawable);

private:
    void init(sf::RenderWindow &window);

    //font 

    //drawable unordered_map
    std::vector<sf::Drawable*> drawables;


    void mainLoop(sf::RenderWindow &window);

    ObjectManager manager;


    /// Reference to the input manager singleton.  Cached here for
    /// convenience.
    inputManager &inp = inputManager::getInstance();

    //renderQueue &rd = renderQueue::getInstance();
};