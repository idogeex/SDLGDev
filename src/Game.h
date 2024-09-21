#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "MenuState.h"

class Game
{
public: 

    static Game* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }

    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    SDL_Renderer* getRenderer() const {return renderer;}

    void handleEvents();
    void update();
    void render();
    void clean();
    bool quit() {return isRunning = false;}
    bool running() {return isRunning;}

    GameObject* m_go;
    Player* m_player;
    GameObject* m_enemy;
    std::vector<SDLGameObject*> m_gameObjects;
    // std::vector<GameObject*> m_gameObjects;

    GameStateMachine* getStateMachine() {return m_pGameStateMachine;}

    static SDL_Renderer* renderer;
    static SDL_Event event;
    static bool isRunning;

private:
    Game();
    ~Game();

    GameStateMachine* m_pGameStateMachine;
    
    static Game* s_pInstance;

    SDL_Window *window;
};