#ifndef PLAYER_OBJECT_HPP
#define PLAYER_OBJECT_HPP

#include "BaseObject.hpp"

enum PlayerState {
    DEFAULT, DEAD,
    LEFT_FOOT_UP, RIGHT_FOOT_UP,
    DUCK_LEFT_FOOT_UP, DUCK_RIGHT_FOOT_UP,
};

class PlayerObject: public BaseObject {

    PlayerState currentState = DEFAULT;
    SDL_Rect allClips[6];

    int framePerStep = 5;

    bool jumping = false;
    bool ducking = false;

    int startJumpingFrame, jumpVelo, accel;
    int framePerVeloDec;

    vector <SDL_Rect> allBoxes[2];

public:

    PlayerObject(): BaseObject(60, 0) {

        allClips[DEFAULT] = {1678, 2, 88, 94};
        allClips[DEAD] = {2030, 2, 88, 94};
        allClips[RIGHT_FOOT_UP] = {1854, 2, 88, 94};
        allClips[LEFT_FOOT_UP] = {1942, 2, 88, 94};
        allClips[DUCK_RIGHT_FOOT_UP] = {2321, 36, 118, 60};
        allClips[DUCK_LEFT_FOOT_UP] = {2203, 36, 118, 60};

        // head
        allBoxes[0].push_back({44, 4, 40, 22});
        allBoxes[0].push_back({44, 26, 32, 8});

        // body
        allBoxes[0].push_back({34, 34, 26, 8});
        allBoxes[0].push_back({24, 42, 44, 8});
        allBoxes[0].push_back({12, 50, 48, 16});
        allBoxes[0].push_back({16, 66, 26, 8});

        // tail
        allBoxes[0].push_back({4, 34, 4, 24});
        allBoxes[0].push_back({8, 42, 4, 20});

        // legs
        allBoxes[0].push_back({24, 74, 8, 16});
        allBoxes[0].push_back({44, 74, 4, 16});

        allBoxes[1].push_back({4, 6, 110, 50});

        collisionBoxes = allBoxes[0];
        clip = allClips[DEFAULT];

        yPos = screenHeight - allClips[DEFAULT].h + 1;

    }
    ~PlayerObject() {}

    void update(int frameCount);

    void makeJump(int frameCount);
    void startDucking();

    void standUp() {
        ducking = false;
        collisionBoxes = allBoxes[0];
    }
    void die() {
        clip = allClips[DEAD];
        xPos += allClips[currentState].w - allClips[DEAD].w;
        yPos += allClips[currentState].h - allClips[DEAD].h;
    }
    bool isJumping() {
        return jumping;
    }
    bool isDucking() {
        return ducking;
    }

};

#endif // PLAYER_OBJECT_HPP
