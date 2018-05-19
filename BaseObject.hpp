#ifndef BASE_OBJECT_HPP
#define BASE_OBJECT_HPP

#include "TextureUtils.hpp"
#include "ScreenSize.hpp"

#include <vector>
#include <iostream>
using namespace std;

class BaseObject {

protected:

    SDL_Rect clip;
    int xPos, yPos;

    vector <SDL_Rect> collisionBoxes;

public:

    BaseObject(int xPos, int yPos): xPos(xPos), yPos(yPos) {}
    ~BaseObject() {}

    int getXPos() {
        return xPos;
    }
    int getYPos() {
        return yPos;
    }

    vector <SDL_Rect> getCollisionBoxes() const {
        vector <SDL_Rect> boxes = collisionBoxes;

        for (int i = 0; i < (int)boxes.size(); ++i) {
            boxes[i].x += xPos;
            boxes[i].y += yPos;
        }
        return boxes;
    }

    void render(SDL_Texture* spriteSheet, SDL_Renderer* renderer) {
        renderTexture(spriteSheet, renderer, xPos, yPos, &clip);
    }

    bool isOutside() {
        return xPos + clip.w < 0;
    }
};

#endif // BASE_OBJECT_HPP
