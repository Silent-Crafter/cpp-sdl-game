#pragma once
#include "Game.hpp"
#include <SDL2/SDL_render.h>

class GameObject {
    private:
        int xpos, ypos;
        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
    
    public:
        SDL_Renderer* renderer;

        GameObject(const char* texturesheet, int x, int y);
        ~GameObject();

        void Update(int xc, int yc);
        void Render();
};