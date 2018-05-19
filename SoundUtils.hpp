#ifndef SOUND_UTILS_HPP
#define SOUND_UTILS_HPP

#include <SDL2/SDL_mixer.h>

class SoundManager {

    Mix_Chunk* hitObstacle = nullptr;
    Mix_Chunk* scoreReached = nullptr;
    Mix_Chunk* buttonPressed = nullptr;

public:

    SoundManager() {
        hitObstacle = Mix_LoadWAV("./wav/hit.wav");
        scoreReached = Mix_LoadWAV("./wav/score-reached.wav");
        buttonPressed = Mix_LoadWAV("./wav/button-press.wav");
    }
    ~SoundManager() {
        Mix_FreeChunk(hitObstacle);
        Mix_FreeChunk(scoreReached);
        Mix_FreeChunk(buttonPressed);
    }
    void playHitSound() {
        Mix_PlayChannel(-1, hitObstacle, 0);
    }
    void playAchievementSound() {
        Mix_PlayChannel(-1, scoreReached, 0);
    }
    void playButtonPressedSound() {
        Mix_PlayChannel(-1, buttonPressed, 0);
    }
};

#endif // SOUND_UTILS_HPP
