/// @file GameObject.hpp
/// @brief Defines the base class for all game objects that can be
/// updated and drawn.

// The GameObject class serves as a simple interface for objects in
// the engine.  Each game object must implement an `update()` method
// which is invoked every frame to perform logic and state changes.
// Because GameObject derives from sf::Drawable, derived classes must
// also override the protected `draw()` method to render themselves to
// an `sf::RenderTarget`.

#pragma once

#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable
{
public:
    virtual ~GameObject() = default;

    /// Update the internal state of the object.  This is called once
    /// per frame by the object manager.  Derived classes should
    /// override this to implement game‑specific behaviour.
    virtual void update() = 0;
};