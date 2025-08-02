// Common definitions for the minimal engine.
//
// This header previously pulled in a very broad set of standard library
// headers (via <bits/stdc++.h>) and even included our own classes.  Doing
// so makes compilation slower, increases coupling between modules and
// encourages circular dependencies.  The minimal engine now exposes only
// the absolutely required definitions.

#pragma once

#include <SFML/Graphics.hpp>   // core SFML types (RenderWindow, Keyboard, etc.)
#include <unordered_set>       // used by inputManager to track pressed keys

// Note: no using‑namespace directives here.  Instead callers should
// fully qualify names (e.g. sf::RenderWindow) or introduce using
// declarations in implementation files as needed.  This avoids
// polluting the global namespace and makes it easier to reason about
// where symbols come from.