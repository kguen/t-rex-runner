#include "TextureUtils.hpp"

SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* renderer) {

    SDL_Surface* tempSurface = IMG_Load(fileName);

    SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 255, 255, 255));
    SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 247, 247, 247));

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

    SDL_FreeSurface(tempSurface);

    return texture;
}

void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int xPos, int yPos, SDL_Rect* clipRect = nullptr) {

    SDL_Rect dstRect;
    dstRect.x = xPos;
    dstRect.y = yPos;

    if (clipRect != nullptr) {
        dstRect.w = clipRect->w;
        dstRect.h = clipRect->h;

    } else {
        SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
    }
    SDL_RenderCopy(renderer, texture, clipRect, &dstRect);
}
