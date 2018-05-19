#include "Ground.hpp"

void Ground::update(int frameCount) {

    if (outOfBorder) {
        clipRects[1].w += velocity;

        clipRects[0].x += velocity;
        clipRects[0].w -= velocity;

        if (clipRects[1].w >= screenWidth) {

            outOfBorder = false;

            clipRects[0].x = clipRects[1].w -= screenWidth;
            clipRects[0].w = screenWidth;
        }

    } else {

        clipRects[0].x += velocity;
        if (clipRects[0].x >= 2400 - screenWidth) {

            outOfBorder = true;

            clipRects[1].x = 2;
            clipRects[1].w = velocity;

            clipRects[0].w -= velocity;
        }
    }
    if (velocity < MAX_VELOCITY && frameCount && frameCount % framePerVeloInc == 0) {
        ++velocity;
    }
}

void Ground::render(SDL_Texture* spriteSheet, SDL_Renderer* renderer) {

    if (outOfBorder) {
        renderTexture(spriteSheet, renderer, 0, yPos, &clipRects[0]);
        renderTexture(spriteSheet, renderer, clipRects[0].w, yPos, &clipRects[1]);

    } else {
        renderTexture(spriteSheet, renderer, 0, yPos, &clipRects[0]);
    }
}
