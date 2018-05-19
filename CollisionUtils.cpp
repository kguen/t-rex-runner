#include "CollisionUtils.hpp"

bool collide(const SDL_Rect& rect1, const SDL_Rect& rect2) {

    const int eps = 5;

    int l1_x = rect1.x, l1_y = rect1.y, r1_x = l1_x + rect1.w - 1, r1_y = l1_y + rect1.h - 1;
    int l2_x = rect2.x, l2_y = rect2.y, r2_x = l2_x + rect2.w - 1, r2_y = l2_y + rect2.h - 1;

    if (l1_x > r2_x - eps || l2_x > r1_x - eps) return false;
    if (l1_y > r2_y - eps || l2_y > r1_y - eps) return false;

    return true;
}

bool collide(const BaseObject* obj1, const BaseObject* obj2) {

    vector <SDL_Rect> boxes1 = obj1->getCollisionBoxes();
    vector <SDL_Rect> boxes2 = obj2->getCollisionBoxes();

    for (int i = 0; i < (int)boxes1.size(); ++i) {
        for (int j = 0; j < (int)boxes2.size(); ++j) {

            if (collide(boxes1[i], boxes2[j]))
                return true;
        }
    }
    return false;
}
