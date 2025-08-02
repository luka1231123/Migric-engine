/// @file objectManager.hpp
/// @brief A simple manager that owns and updates all active game objects.

// The object manager keeps a collection of objects derived from
// GameObject.  It provides methods to update all objects each frame
// and to draw them to an SFML window.  It also offers a templated
// `create` function for constructing new objects in place and
// automatically tracking them.

#pragma once

#include <vector>
#include <memory>
#include <type_traits>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class ObjectManager
{
public:
    ObjectManager() = default;
    ObjectManager(const ObjectManager &) = delete;
    ObjectManager &operator=(const ObjectManager &) = delete;

    /// Create a new game object of type `T` with the given
    /// constructor arguments.  The object must derive from
    /// GameObject.  The returned shared pointer can be used to
    /// interact with the object directly.  The manager retains
    /// ownership and will handle updating and drawing automatically.
    template <typename T, typename... Args>
    std::shared_ptr<T> create(Args &&... args)
    {
        static_assert(std::is_base_of<GameObject, T>::value,
                      "T must derive from GameObject");
        auto obj = std::make_shared<T>(std::forward<Args>(args)...);
        objects.push_back(obj);
        return obj;
    }

    /// Invoke update on every managed object.  Should be called once
    /// per frame prior to drawing.
    void updateAll()
    {
        for (auto &obj : objects)
        {
            obj->update();
        }
    }

    /// Draw all managed objects to the provided render window.
    /// Typically called once per frame after updates.
    void drawAll(sf::RenderWindow &window)
    {
        for (auto &obj : objects)
        {
            window.draw(*obj);
        }
    }

private:
    std::vector<std::shared_ptr<GameObject>> objects;
};