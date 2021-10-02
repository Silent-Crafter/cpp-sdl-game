#include "../include/Game.hpp"
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

Game *game = nullptr;

int main(int argc, const char * argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    // main game loop
    while (game->running())             // run until Game::isRunning is True
    {
        // Returns a value representing the number of ms since the SDL library initialized.
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        // fps capping to 60
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay);
        }
    }

    // the DESTROYER
    game->clean();

    return 0;
}