#include "Game.hpp"

void Game::initSDL(const char* windowTitle, int screenWidth, int screenHeight, bool fullscreen) {

    int flags = 0;

    if (!SDL_Init(SDL_INIT_EVERYTHING)) cout << "SDL initialised!...\n";
    if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

    window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              screenWidth, screenHeight, flags);

    if (window != nullptr) cout << "Window created!...\n";

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer != nullptr) {
        cout << "Renderer created!...\n";
        //SDL_SetRenderDrawColor(renderer, 247, 247, 247, 255);
    }

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != -1) {
        cout << "SDL_Mixer initialised!...\n";
    }

    spriteSheet = loadTexture("./image/sprite_sheet_2x.png", renderer);
    cout << "Sprite sheet loaded!...\n";
}

void Game::freeMemory() {

    delete ground;
    delete player;
    delete clouds;
    delete obstacles;
	delete soundEffects;

    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	cout << "\nQuitting success!\n";
}

void Game::reset() {

    delete ground;
    delete player;
    delete clouds;
    delete obstacles;

    createObjects();
    frameCount = 0;
    bgColorCode = 247;

    lost = false;
}

void Game::handleEvents() {

    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {

    case SDL_QUIT:
        running = false;
        break;

    case SDL_KEYDOWN:

        switch(event.key.keysym.sym) {

        case SDLK_ESCAPE:
            running = false;
            break;

        case SDLK_UP:
        case SDLK_SPACE:

            gameStarted = true;

            if (lost) {
                reset();

            } else if (!player->isJumping() && !player->isDucking()) {
                player->makeJump(frameCount);
                soundEffects->playButtonPressedSound();
            }
            break;

        case SDLK_DOWN:

            gameStarted = true;

            if (!lost) player->startDucking();
            break;

        }
        break;

    case SDL_KEYUP:
        switch(event.key.keysym.sym) {

        case SDLK_DOWN:

            if (player->isDucking()) player->standUp();
            break;
        }
        break;

    default:
        break;
    }
}

void Game::createObjects() {

    soundEffects = new SoundManager();

    ground = new Ground();
    clouds = new Clouds();

    score = new Score(screenWidth - 110, 16);

    player = new PlayerObject();
    obstacles = new Obstacles();
}

void Game::update() {

    if (nightModeOn) {

        if (bgColorCode > 0) bgColorCode -= 2;
        if (bgColorCode < 0 || lost) bgColorCode = 0;

    } else {

        if (bgColorCode < 247) bgColorCode += 2;
        if (bgColorCode > 247 || lost) bgColorCode = 247;
    }

    if (lost || !gameStarted) return;

    clouds->update(frameCount);
    ground->update(frameCount);

    player->update(frameCount);
    obstacles->update(frameCount, ground->getVelocity());

    score->update(frameCount);

    if (frameCount && frameCount % 600 == 0) {
        soundEffects->playAchievementSound();
    }
    if (frameCount && frameCount % 4200 == 0) {
        nightModeOn = true;
    }
    if (frameCount % 4200 == 1200) {
        nightModeOn = false;
    }
    ++frameCount;
}

void Game::checkCollision() {

    if (lost || !gameStarted) return;

    vector <BaseObject*> obstacleLists = obstacles->getObstacles();

    for (int i = 0; i < (int)obstacleLists.size(); ++i) {

        if (collide(player, obstacleLists[i])) {
            lost = true;
            player->die();
            soundEffects->playHitSound();

            if (highScore == nullptr) {
                highScore = new Score(screenWidth - 230, 16);
            }
            if (highScore->getScore() < score->getScore()) {
                highScore->update(frameCount);
            }
        }
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, bgColorCode, bgColorCode, bgColorCode, 255);

    // background elements
    ground->render(spriteSheet, renderer);
    clouds->render(spriteSheet, renderer);

    // score
    if (lost) {
        score->noFlashing();
        score->update(frameCount);
    }
    score->render(spriteSheet, renderer, frameCount);

    if (highScore != nullptr) {

        // render "HI"
        SDL_Rect clip = {1494, 2, 38, 21};
        renderTexture(spriteSheet, renderer, screenWidth - clip.w - 250, 16, &clip);

        highScore->noFlashing();
        highScore->render(spriteSheet, renderer, frameCount);
    }

    // main objects
    player->render(spriteSheet, renderer);
    obstacles->render(spriteSheet, renderer);

    if (lost) renderGameOverScreen();

    SDL_RenderPresent(renderer);
}

void Game::renderGameOverScreen() {

    SDL_Rect clip = {1294, 29, 381, 21};
    renderTexture(spriteSheet, renderer, (screenWidth - clip.w) / 2, 100, &clip);

    clip = {2, 2, 72, 64};
    renderTexture(spriteSheet, renderer, (screenWidth - clip.w) / 2, 150, &clip);
}
