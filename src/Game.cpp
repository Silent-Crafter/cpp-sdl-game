#include "../include/Game.hpp"
#include "../include/GameObject.hpp"
#include "../include/TextureManager.hpp"
#include "../include/Map.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    // if SDL successfully initializes everything create window and renderer
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

        // SDL_CreateWindow's flags can be represented with numbers
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            cout << "window created" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            cout << "renderer created" << endl;
        }

        isRunning = true;
    }
    else {
        cout << "Error occured" << SDL_GetError() << endl;
        isRunning = false;
    }

    // created 7 initialized other objects
    // can do the same way as above with error handling but me lazy
    player = new GameObject("assets/player2.png", 0, 0);
    enemy = new GameObject("assets/ballL.png", 50, 50);

    map = new Map();
}

void Game::handleEvents()
{
    SDL_Event event;
    // fetch and feed all events to this variable
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:              // for the 'X' button on titlebar to work. SD_QUIT = SIGTERM
            isRunning = false;      // to get out of while loop in main.cpp
            break;

        default:
            break;
    }
}

void Game::update()                 // update objects(entities). movements can go here.
{
    player->Update(5, 5);
    enemy->Update(5, 5);
}

void Game::render()
{
    SDL_RenderClear(renderer);
    // renders all objects you want to here. ORDER IS IMPORTANT
    map->DrawMap();
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
    
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    cout << "Stopped!" << endl;
}