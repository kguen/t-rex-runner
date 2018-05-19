#ifndef SCORE_HPP
#define SCORE_HPP

#include "DigitObject.hpp"
#include "TextureUtils.hpp"

class Score {

    DigitObject** digits;

    bool flashing = false;

    int score = 0;
    int startBlinkFrame;

public:

    Score(int xPos, int yPos);
    ~Score();

    int getScore() {
        return score;
    }

    void noFlashing() {
        flashing = false;
    }

    void update(int frameCount);

    void render(SDL_Texture*, SDL_Renderer*, int frameCount);
};

#endif // SCORE_HPP
