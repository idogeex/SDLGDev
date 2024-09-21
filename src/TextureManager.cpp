#include "TextureManager.h"
#include <map>
#include <iostream>

TextureManager* TextureManager::s_pInstance = 0;

SDL_Texture* TextureManager::LoadTexture(std::string fileName, std::string texID)
{
    SDL_Surface* tmpSurface = IMG_Load(fileName.c_str());
    SDL_Texture* playerTex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    if(playerTex != 0)
    {
        texMap[texID] = playerTex;
        return 0;
    }

    return playerTex;
}

void TextureManager::draw(std::string texID, int x, int y, int width, int height, SDL_Renderer* ren)
{  
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopy(Game::renderer, texMap[texID], &srcRect, &destRect);
}

void TextureManager::drawFrame(std::string texID, int x, int y, int width, int height, int curR, int curFr, SDL_Renderer* ren, SDL_RendererFlip flip)
{  
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * curFr;
    srcRect.y = height * (curR - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(Game::renderer, texMap[texID], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::clearFromTextureMap(std::string id)
{
    texMap.erase(id);
}