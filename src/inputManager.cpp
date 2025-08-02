/// @file inputManager.cpp
/// @brief Implementation of the minimal input manager.

#include "inputManager.hpp"

using sf::Event;
using sf::Keyboard;
using sf::Mouse;
using sf::RenderWindow;
using sf::Time;
using sf::Vector2i;

inputManager &inputManager::getInstance()
{
    static inputManager instance;
    return instance;
}

void inputManager::processInput(RenderWindow &window)
{
    updateMouse(window);

    Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            window.close();
            break;
        case Event::KeyPressed:
            handleKeyPress(event.key.code);
            break;
        case Event::KeyReleased:
            handleKeyRelease(event.key.code);
            break;
        case Event::TextEntered:
            if (event.text.unicode == 8) { // Backspace
                if (!typedText.empty()) typedText.pop_back();
            } else if (event.text.unicode < 128) // Only handle ASCII characters
            {
                typedText += static_cast<wchar_t>(event.text.unicode);
            }
            break;
        }
    }
    // Tick handling is deferred to updateTime() to ensure it is
    // synchronised with time measurement.
}

bool inputManager::isKeyPressed(Keyboard::Key key) const
{
    return pressedKeys.find(key) != pressedKeys.end();
}

const std::wstring &inputManager::getTypedText() const {
    return typedText;
}

void inputManager::clearTypedText() {
    typedText.clear();
}

void inputManager::updateTime()
{
    // Measure time elapsed since last update.
    elapsed = clock.restart();
    const float seconds = elapsed.asSeconds();
    if (seconds > 0.0f)
        fps = 1.0f / seconds;

    timeSince += elapsed;


    tickRemaining -= elapsed;
    if (tickRemaining <= sf::Time::Zero)
    {
        tick = true;
        tickRemaining += sf::seconds(tickInterval);
    }
    else
    {
        tick = false;
    }
}

void inputManager::handleKeyPress(Keyboard::Key key)
{
    pressedKeys.insert(key);
}

void inputManager::handleKeyRelease(Keyboard::Key key)
{
    pressedKeys.erase(key);
}

void inputManager::updateMouse(RenderWindow &window)
{
    prevLeftDown = leftDown;
    prevRightDown = rightDown;
    oldPos = pos;

    leftDown = Mouse::isButtonPressed(Mouse::Left);
    rightDown = Mouse::isButtonPressed(Mouse::Right);

    pos = Mouse::getPosition(window);
}