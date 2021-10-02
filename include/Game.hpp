#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

class Game{
    private:
        int count = 0;
        bool isRunning;
        SDL_Window *window;
        SDL_Surface *surface;
        SDL_Texture* playerTex;

    public:
        static SDL_Renderer* renderer;

        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();

        bool running(){ return isRunning; }
};