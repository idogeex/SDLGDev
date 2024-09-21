#include "GamveOverState.h"
#include "TextureManager.h"
#include "Game.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void GameOverState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool GameOverState::onEnter()
{
    if(TextureManager::Instance()->LoadTexture("res/mainmenubtn.png", "mainbutton"))
    {
        return false;
    }

    if(TextureManager::Instance()->LoadTexture("res/restartbtn.png", "restart"))
    {
        return false;
    }

    GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 128, 96, "mainbutton"), s_gameOverToMain);
    GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 128, 96, "restart"), s_restartPlay);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "Entering GameOver" << std::endl;
    return true;
}

bool GameOverState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TextureManager::Instance()->clearFromTextureMap("mainbutton");
    TextureManager::Instance()->clearFromTextureMap("restart");

    std::cout << "exitiing GameOverState" << std::endl;
    return true;
}

void GameOverState::s_gameOverToMain()
{
    Game::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::s_restartPlay()
{
    Game::Instance()->getStateMachine()->changeState(new PlayState());
}