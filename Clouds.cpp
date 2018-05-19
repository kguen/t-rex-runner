#include "Clouds.hpp"

Clouds::~Clouds() {

    for (int i = 0; i < (int)cloudQueue.size(); ++i) {
        delete cloudQueue[i];
    }
    cloudQueue.clear();

}

void Clouds::pushNewCloud() {
    CloudObject* cloud = new CloudObject();

    cloudQueue.push_back(cloud);
}

void Clouds::popCloud() {

    delete cloudQueue.front();
    cloudQueue.pop_front();
}

void Clouds::update(int frameCount) {
    if (frameCount - lastCloudPopUpFrame == frameBeforeNextCloud) {

        pushNewCloud();

        lastCloudPopUpFrame = frameCount;
        frameBeforeNextCloud = 100 + rand() % 301;
    }
    if (!cloudQueue.empty() && cloudQueue.front()->isOutside()) {
        popCloud();
    }

    for (int i = 0; i < (int)cloudQueue.size(); ++i) {
        cloudQueue[i]->update();
    }
}

void Clouds::render(SDL_Texture* spriteSheet, SDL_Renderer* renderer) {
    for (int i = 0; i < (int)cloudQueue.size(); ++i) {
        cloudQueue[i]->render(spriteSheet, renderer);
    }
}
