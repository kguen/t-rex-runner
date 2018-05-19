#include "Score.hpp"

Score::Score(int xPos, int yPos) {
    digits = new DigitObject*[5];

    for (int i = 0; i < 5; ++i) {
        digits[i] = new DigitObject(xPos + i * 20, yPos);
        digits[i]->setValue(0);
    }
}

Score::~Score() {
    for (int i = 0; i < 5; ++i) {
        delete digits[i];
    }
    delete digits;
}

void Score::update(int frameCount) {
    score = frameCount / 6;

    if (flashing) {

        if (frameCount - startBlinkFrame == 120) {
            flashing = false;
        }

    } else {

        int currentScore = score;

        for (int i = 4; currentScore; --i) {
            digits[i]->setValue(currentScore % 10);
            currentScore /= 10;
        }
    }

    if (frameCount && frameCount % 600 == 0) {
        flashing = true;
        startBlinkFrame = frameCount;
    }
}

void Score::render(SDL_Texture* spriteSheet, SDL_Renderer* renderer, int frameCount) {
    for (int i = 0; i < 5; ++i) {
        if (!flashing || (frameCount - startBlinkFrame) % 45 > 25) {
            digits[i]->render(spriteSheet, renderer);
        }
    }
}
