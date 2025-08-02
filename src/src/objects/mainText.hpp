/// @file mainText.hpp
/// @brief A simple game object displaying typed text on the screen.

// The MainText class listens to the input manager to retrieve the
// current text typed by the user and displays it using SFML's
// rendering facilities.  It derives from GameObject so that the
// object manager can update and draw it automatically each frame.

#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "../inputManager.hpp"

class MainText : public GameObject
{
public:
    MainText();
    void update() override;

protected:
    /// Draw the text to the target.  Called automatically by
    /// GameObject's drawAll implementation via sf::RenderWindow.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::Text text;
    inputManager &inp;
};