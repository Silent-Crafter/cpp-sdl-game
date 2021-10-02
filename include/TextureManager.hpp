#pragma once

#include "Game.hpp"
#include <SDL2/SDL_render.h>

class TextureManager {
    public:
        static SDL_Texture* Loadtexture(const char* filename);
        static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};