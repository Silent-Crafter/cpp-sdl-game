#include "../include/GameObject.hpp"
#include "../include/TextureManager.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>

GameObject::GameObject(const char* texturesheet, int x, int y){
    objTexture = TextureManager::Loadtexture(texturesheet);

    xpos = x;
    ypos = y;
}


void GameObject::Update(int xc, int yc)             // Movement and stuff
{
    xpos ++;
    ypos ++;

    srcRect.h = 380;
    srcRect.w = 240;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.w = srcRect.w * 1/2;
    destRect.h = srcRect.h * 1/2;
    destRect.x = xpos;
    destRect.y = ypos;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}