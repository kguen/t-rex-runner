#include "Game.hpp"

const int FPS = 60;
const int timePerFrame = 1000 / FPS;

int screenWidth = 1300, screenHeight = 350;

int main(int argc, char* argv[]) {

    srand(time(NULL));

    Game* game = new Game();

    Uint32 frameStart;
    int frameTime;

    while (game->isRunning()) {

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();
        game->checkCollision();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < timePerFrame) SDL_Delay(timePerFrame - frameTime);
    }
    delete game;

    return 0;
}
