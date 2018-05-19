#include "Obstacles.hpp"

Obstacles::~Obstacles() {

    for (int i = 0; i < (int)cactusQueue.size(); ++i) {
        delete cactusQueue[i];
    }
    cactusQueue.clear();

    for (int i = 0; i < (int)birdQueue.size(); ++i) {
        delete birdQueue[i];
    }
    birdQueue.clear();
}

vector <BaseObject*> Obstacles::getObstacles() {

    vector <BaseObject*> allObstacles;

    for (int i = 0; i < (int)cactusQueue.size(); ++i) {
        allObstacles.push_back(cactusQueue[i]);
    }
    for (int i = 0; i < (int)birdQueue.size(); ++i) {
        allObstacles.push_back(birdQueue[i]);
    }

    return allObstacles;
}

void Obstacles::pushNewObstacle(int obstacleType) {

    if (obstacleType == 0) {

        CactusObject* cactus = new CactusObject();
        cactusQueue.push_back(cactus);

    } else {

        BirdObject* bird = new BirdObject();
        birdQueue.push_back(bird);
    }
}

void Obstacles::popObstacle(int obstacleType) {

    if (!obstacleType) {

        delete cactusQueue.front();
        cactusQueue.pop_front();

    } else if (!birdQueue.empty()) {

        delete birdQueue.front();
        birdQueue.pop_front();
    }
}

void Obstacles::update(int frameCount, int velocity) {

    if (frameCount - lastObstaclePopUpFrame == frameBeforeNextObstacle) {

        if (frameCount >= 1500) {

            int randInt = rand() % 5;

            if (!randInt) pushNewObstacle(1);
            else pushNewObstacle(0);

        } else {
            pushNewObstacle(0);
        }

        lastObstaclePopUpFrame = frameCount;

        int prob = rand() % 100;
        if (prob < 60) {
            frameBeforeNextObstacle = 40 + rand() % 20;

        } else if (prob < 80) {
            frameBeforeNextObstacle = 60 + rand() % 30;

        } else {
            frameBeforeNextObstacle = 90 + rand() % 20;
        }

    }

    if (!cactusQueue.empty() && cactusQueue.front()->isOutside()) {
        popObstacle(0);
    }
    if (!birdQueue.empty() && birdQueue.front()->isOutside()) {
        popObstacle(1);
    }

    for (int i = 0; i < (int)cactusQueue.size(); ++i) {
        cactusQueue[i]->update(velocity);
    }
    for (int i = 0; i < (int)birdQueue.size(); ++i) {
        birdQueue[i]->update(frameCount, velocity);
    }
}

void Obstacles::render(SDL_Texture* spriteSheet, SDL_Renderer* renderer) {

    for (int i = 0; i < (int)cactusQueue.size(); ++i) {
        cactusQueue[i]->render(spriteSheet, renderer);
    }
    for (int i = 0; i < (int)birdQueue.size(); ++i) {
        birdQueue[i]->render(spriteSheet, renderer);
    }
}
