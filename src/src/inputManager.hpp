/// @file inputManager.hpp
/// @brief A minimal input manager for the stripped down engine.

/// This class centralises handling of keyboard and mouse state as
/// well as simple timing functionality.  It is implemented as a
/// singleton so that the engine can access a single shared instance
/// without needing to plumb references everywhere.  To use it call
/// `inputManager::getInstance()` and then process input each frame via
/// `processInput()`.  Elapsed time and frames per second can be
/// queried via `updateTime()`.

#pragma once


#include <SFML/Graphics.hpp>
#include <unordered_set>

// Do not pollute global namespace.  Use fully qualified sf:: names
// throughout the header to make dependencies obvious.  Only when
// implementing methods in the cpp file do we introduce using
// declarations for brevity.

class inputManager
{
public:
    /// Get the singleton instance of the input manager.
    static inputManager &getInstance();

    
    void processInput(sf::RenderWindow &window);

    [[nodiscard]] bool isKeyPressed(sf::Keyboard::Key key) const;

    void updateTime();

    [[nodiscard]] sf::Vector2i getPos() const { return pos; }

    [[nodiscard]] sf::Vector2i getOldPos() const { return oldPos; }

    [[nodiscard]] bool leftPressed() const { return leftDown; }

    [[nodiscard]] bool leftPressedLast() const { return prevLeftDown; }

    [[nodiscard]] bool rightPressed() const { return rightDown; }

    [[nodiscard]] bool rightPressedLast() const { return prevRightDown; }

    [[nodiscard]] bool tickOccurred() const { return tick; }

    void setTickInterval(float seconds) { tickInterval = seconds; resetTick(); }

    [[nodiscard]] float getFPS() const { return fps; }

    const std::wstring &getTypedText() const;
    
    void loadFont(const std::string &fontPath);

    void clearTypedText();

    sf::Font font;


private:
    // Constructor is private to enforce singleton semantics.
    inputManager() = default;

    // Deleted copy constructor and assignment to prevent copies.
    inputManager(const inputManager &) = delete;

    inputManager &operator=(const inputManager &) = delete;

    std::unordered_set<sf::Keyboard::Key> pressedKeys;

    std::wstring typedText;

    // Handle a key press event by inserting the key into the pressed set.
    void handleKeyPress(sf::Keyboard::Key key);
    // Handle a key release event by erasing the key from the pressed set.
    void handleKeyRelease(sf::Keyboard::Key key);
    // Update mouse buttons and position.  Must be called once per frame.
    void updateMouse(sf::RenderWindow &window);
    // Reset the internal tick countdown to its full interval.
    void resetTick() { tickRemaining = sf::seconds(tickInterval); tick = false; }


    sf::Vector2i pos{0, 0};
    sf::Vector2i oldPos{0, 0};
    bool leftDown{false};
    bool prevLeftDown{false};
    bool rightDown{false};
    bool prevRightDown{false};


    
    bool tick{false};
    float tickInterval{0.2f};
    sf::Time tickRemaining{sf::seconds(0.0f)};
    sf::Clock clock;
    sf::Time elapsed;
    sf::Time timeSince;
    float fps{0.0f};
};