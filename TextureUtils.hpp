#ifndef TEXTURE_UTILS_HPP
#define TEXTURE_UTILS_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* renderer);

void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int xPos, int yPos, SDL_Rect* clipRect);

#endif // TEXTURE_UTILS_HPP
