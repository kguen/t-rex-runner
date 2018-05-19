#ifndef COLLISION_UTILS_HPP
#define COLLISION_UTILS_HPP

#include "BaseObject.hpp"

bool collide(const SDL_Rect& rect1, const SDL_Rect& rect2);

bool collide(const BaseObject* obj1, const BaseObject* obj2);

#endif // COLLISION_UTILS_HPP
