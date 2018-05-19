#ifndef BIRD_OBJECT_HPP
#define BIRD_OBJECT_HPP

#include "BaseObject.hpp"
#include <cstdlib>
#include <cmath>

class BirdObject: public BaseObject {

    SDL_Rect allClips[2];
    vector <SDL_Rect> allBoxes[2];

    const int framePerFlaps = 20;
    int currentState = 0;

public:

    BirdObject(): BaseObject(screenWidth, 0) {

        int randInt = rand() % 3;

        if (randInt == 0) {
            yPos = 140;

        } else if (randInt == 1) {
            yPos = 225;

        } else {
            yPos = 290;
        }

        allClips[0] = {260, 14, 92, 68};
        allClips[1] = {352, 2, 92, 60};

        // wings up
        allBoxes[0].push_back({4, 12, 12, 12});
        allBoxes[0].push_back({16, 4, 12, 20});
        allBoxes[0].push_back({28, 20, 36, 8});
        allBoxes[0].push_back({32, 28, 56, 16});
        allBoxes[0].push_back({36, 44, 16, 8});
        allBoxes[0].push_back({36, 52, 8, 12});

        // wings down
        allBoxes[1].push_back({4, 24, 12, 12});
        allBoxes[1].push_back({16, 16, 12, 20});
        allBoxes[1].push_back({32, 4, 12, 12});
        allBoxes[1].push_back({36, 16, 24, 16});
        allBoxes[1].push_back({28, 32, 36, 8});
        allBoxes[1].push_back({32, 40, 56, 16});

    }

    void update(int frameCount, int velocity) {

        xPos -= velocity;

        if (frameCount % framePerFlaps == framePerFlaps - 1) {
            currentState = 1 - currentState;
            yPos += (1 - currentState * 2) * 12;
        }

        clip = allClips[currentState];
        collisionBoxes = allBoxes[currentState];
    }

};

#endif // BIRD_OBJECT_HPP
