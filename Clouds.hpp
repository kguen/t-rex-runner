#ifndef CLOUDS_HPP
#define CLOUDS_HPP

#include "CloudObject.hpp"
#include <deque>
#include <cstdlib>

class Clouds {

    std::deque <CloudObject*> cloudQueue;

    int frameBeforeNextCloud = 0;
    int lastCloudPopUpFrame = 0;

    void pushNewCloud();

    void popCloud();

public:

    Clouds() {}
    ~Clouds();

    void update(int frameCount);

    void render(SDL_Texture*, SDL_Renderer*);

};

#endif // CLOUDS_HPP
