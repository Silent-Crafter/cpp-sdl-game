#pragma once
#include "Game.hpp"
#include "../include/TextureManager.hpp"
#include <SDL2/SDL_render.h>

class Map
{
    private:

        int map[20][25];

        SDL_Rect src, dest;
        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;

    public:
        Map();
        ~Map();

        void LoadMap(int arr[20][25]);
        void DrawMap();
};