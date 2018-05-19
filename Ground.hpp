#ifndef GROUND_HPP
#define GROUND_HPP

#include "TextureUtils.hpp"
#include "ScreenSize.hpp"

class Ground {

    SDL_Rect clipRects[2];

    int velocity = 10;
    int yPos;

    const int MAX_VELOCITY = 25;
    const int framePerVeloInc = 480;

    bool outOfBorder = false;

public:
    Ground() {
        clipRects[0] = clipRects[1] = {2, 104, screenWidth, 26};
        yPos = screenHeight - clipRects[0].h + 1;
    }
    ~Ground() {}

    int getVelocity() {
        return velocity;
    }

    void update(int frameCount);

    void render(SDL_Texture*, SDL_Renderer*);
};

#endif // GROUND_HPP
