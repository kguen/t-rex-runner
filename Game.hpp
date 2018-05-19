#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <ctime>
using namespace std;

#include "ScreenSize.hpp"
#include "CollisionUtils.hpp"
#include "SoundUtils.hpp"

#include "Ground.hpp"
#include "Clouds.hpp"
#include "Score.hpp"
#include "PlayerObject.hpp"
#include "Obstacles.hpp"

class Game {

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* spriteSheet;

    SoundManager* soundEffects;

    bool running = true;
    bool lost = false;
    bool gameStarted = false;
    bool nightModeOn = false;

    int frameCount = 0;
    int bgColorCode = 247;

    Ground* ground;
    Clouds* clouds;

    Score *score, *highScore = nullptr;

    PlayerObject* player;
    Obstacles* obstacles;

    void initSDL(const char* windowtitle, int screenWidth, int screenHeight, bool fullscreen);
    void createObjects();

    void freeMemory();

    void renderGameOverScreen();
    void reset();

public:
    Game() {
        initSDL("T-Rex Runner!", screenWidth, screenHeight, false);
        createObjects();
    }
    ~Game() {
        freeMemory();
    }

    void handleEvents();

    void update();
    void render();

    void checkCollision();

    bool isRunning() {
        return running;
    }
};

#endif // GAME_HPP
