/// @file mainText.cpp
/// @brief Implementation of the MainText game object.

#include "mainText.hpp"
#include <iostream>

MainText::MainText() : inp(inputManager::getInstance())
{
    // Set the font (must be loaded before this)
    text.setFont(inp.font);

    // Initial text setup
    text.setString(inp.getTypedText()+ L"გამარჯობა");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(20, 20);
}

void MainText::update()
{
    // Update the text content each frame
    text.setString(inp.getTypedText());
}

void MainText::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text, states);
}
