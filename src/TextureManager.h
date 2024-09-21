#pragma once

#include "Game.h"
#include <string>
#include <map>

class TextureManager 
{
public:
    static TextureManager* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    } 

    SDL_Texture* LoadTexture(std::string fileName, std::string texID);
    void draw(std::string texID, int x, int y, int width, int height, SDL_Renderer* ren);
    void drawFrame(std::string texID, int x, int y, int width, int height, int curR, int curFr, SDL_Renderer* ren, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void clearFromTextureMap(std::string texID);

    std::map<std::string, SDL_Texture*> texMap;
private:
    TextureManager() {}
    ~TextureManager() {}
    
    TextureManager(const TextureManager&);
	TextureManager& operator=(const TextureManager&);

    static TextureManager* s_pInstance;
};