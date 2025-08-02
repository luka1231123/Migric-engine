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

class gameManager
{
public:
    /// Launch the engine.  This call blocks until the user closes
    /// the window or presses Escape.  Constructing and running a
    /// gameManager does not throw; any SFML exceptions will be
    /// propagated on failure to create the window.
    void run();

private:
    /// Set up the render window used to receive input events.  The
    /// window is intentionally simple: fixed size, default style and
    /// optional vertical sync.  No drawing is performed on this
    /// window in the minimal engine.
    void init(sf::RenderWindow &window);

    /// Execute the main loop.  Processes input and timing each
    /// iteration.  The loop terminates when the window is closed or
    /// the Escape key is pressed.
    void mainLoop(sf::RenderWindow &window);

    /// Reference to the input manager singleton.  Cached here for
    /// convenience.
    inputManager &inp = inputManager::getInstance();
};