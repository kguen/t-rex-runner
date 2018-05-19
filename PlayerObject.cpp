#include "PlayerObject.hpp"

void PlayerObject::makeJump(int frameCount) {

    jumping = true;
    startJumpingFrame = frameCount;

    jumpVelo = 20;
    framePerVeloDec = 4;
    accel = 5;

    currentState = DEFAULT;
}

void PlayerObject::startDucking() {

    ducking = true;

    if (!jumping) {
        collisionBoxes = allBoxes[1];

    } else {

        accel = 10;
        jumpVelo = -accel;
    }
}

void PlayerObject::update(int frameCount) {

    if (jumping) {

        if (frameCount > startJumpingFrame && (frameCount - startJumpingFrame) % framePerVeloDec == 0) {
            jumpVelo -= accel;
        }
        if (yPos - jumpVelo >= screenHeight - allClips[DEFAULT].h + 1) {

            jumping = false;

            if (ducking) {
                yPos = screenHeight - allClips[DUCK_LEFT_FOOT_UP].h + 1;
                currentState = DUCK_RIGHT_FOOT_UP;

                collisionBoxes = allBoxes[1];

            } else {
                yPos = screenHeight - allClips[DEFAULT].h + 1;
                currentState = RIGHT_FOOT_UP;
            }

        } else {
            yPos -= jumpVelo;
        }

    } else if (frameCount % framePerStep == 0) {

        if (ducking) {
            yPos = screenHeight - allClips[DUCK_LEFT_FOOT_UP].h + 1;

            if (currentState == DUCK_LEFT_FOOT_UP) {
                currentState = DUCK_RIGHT_FOOT_UP;

            } else {
                currentState = DUCK_LEFT_FOOT_UP;
            }

        } else {
            yPos = screenHeight - allClips[DEFAULT].h + 1;

            if (currentState == DEFAULT || currentState == LEFT_FOOT_UP) {
                currentState = RIGHT_FOOT_UP;

            } else {
                currentState = LEFT_FOOT_UP;
            }
        }
    }
    clip = allClips[currentState];
}


