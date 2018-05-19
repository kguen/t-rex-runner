#ifndef OBSTACLES_HPP
#define OBSTACLES_HPP

#include "CactusObject.hpp"
#include "BirdObject.hpp"
#include <deque>

class Obstacles {

    std::deque <BirdObject*> birdQueue;
    std::deque <CactusObject*> cactusQueue;

    int frameBeforeNextObstacle = 120;
    int lastObstaclePopUpFrame = 0;

    void pushNewObstacle(int obstacleType);

    void popObstacle(int obstacleType);

public:

    Obstacles() {}
    ~Obstacles();

    vector <BaseObject*> getObstacles();

    void update(int frameCount, int velocity);

    void render(SDL_Texture*, SDL_Renderer*);

};

#endif // OBSTACLES_HPP
