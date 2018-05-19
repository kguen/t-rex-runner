#ifndef CACTUS_OBJECT_HPP
#define CACTUS_OBJECT_HPP

#include "BaseObject.hpp"
#include <cstdlib>

class CactusObject: public BaseObject {

public:

    CactusObject(): BaseObject(screenWidth, 0) {

        int cactusType;
        int prob = rand() % 100;

        if (prob < 50) {
            cactusType = rand() % 2 ? 0 : 3;

        } else if (prob < 90) {
            cactusType = rand() % 2 ? 1 : 4;

        } else {
            cactusType = rand() % 2 ? 2 : 5;
        }

        if (cactusType < 3)  {
            yPos = screenHeight - 70;

        } else {
            yPos = screenHeight - 96;
        }

        switch(cactusType) {

        case 0:
            clip = {446, 2, 34, 70};

            collisionBoxes.push_back({2, 18, 10, 28});
            collisionBoxes.push_back({12, 2, 10, 66});
            collisionBoxes.push_back({22, 10, 10, 28});

            break;

        case 1:
            clip = {480, 2, 68, 70};

            collisionBoxes.push_back({2, 18, 10, 28});
            collisionBoxes.push_back({12, 2, 44, 66});
            collisionBoxes.push_back({56, 10, 10, 32});

            break;

        case 2:
            clip = {548, 2, 102, 70};

            collisionBoxes.push_back({2, 18, 10, 28});
            collisionBoxes.push_back({12, 2, 78, 66});
            collisionBoxes.push_back({90, 10, 10, 32});

            break;

        case 3:
            clip = {652, 2, 50, 100};

            collisionBoxes.push_back({2, 26, 16, 38});
            collisionBoxes.push_back({18, 2, 14, 94});
            collisionBoxes.push_back({32, 22, 16, 40});

            break;

        case 4:
            clip = {702, 2, 100, 100};

            collisionBoxes.push_back({2, 26, 16, 38});
            collisionBoxes.push_back({18, 2, 14, 94});
            collisionBoxes.push_back({32, 22, 36, 48});
            collisionBoxes.push_back({68, 2, 14, 94});
            collisionBoxes.push_back({82, 22, 16, 40});

            break;

        case 5:
            clip = {802, 2, 150, 100};

            collisionBoxes.push_back({2, 26, 16, 38});
            collisionBoxes.push_back({18, 2, 14, 94});
            collisionBoxes.push_back({32, 22, 30, 44});
            collisionBoxes.push_back({62, 6, 10, 90});
            collisionBoxes.push_back({72, 14, 46, 82});
            collisionBoxes.push_back({118, 2, 14, 94});
            collisionBoxes.push_back({132, 24, 16, 38});

            break;

        }

    }

    void update(int velocity) {
        xPos -= velocity;
    }

};

#endif // CACTUS_OBJECT_HPP
