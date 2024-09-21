#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "PlayState.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
bool Game::isRunning = false;
Game* Game::s_pInstance = 0;



int curFr;

Game::Game() {}
Game:: ~Game() {}


bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialised!" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
        {
            std::cout << "Window Created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 66, 66, 66, 255);
            std::cout << "Renderer Created!" << std::endl;
        }
    }

        // m_gameObjects.push_back(new Player(new LoaderParams(100, 400, 32, 32, "animate")));
        // m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 32, 32, "animate")));


        m_pGameStateMachine = new GameStateMachine();
        m_pGameStateMachine->changeState(new MenuState());
        

        TextureManager::Instance()->LoadTexture("res/player_anims.png", "animate");
        
        isRunning = true;
}

void Game::handleEvents()
{
    InputHandler::Instance()->update();

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
        m_pGameStateMachine->changeState(new PlayState());
    }
}

void Game::update()
{

    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
    m_pGameStateMachine->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);

    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }

    m_pGameStateMachine->render();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}