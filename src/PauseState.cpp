#include "PauseState.h"
#include "TextureManager.h"
#include "Game.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::update()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void PauseState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool PauseState::onEnter()
{
    if(TextureManager::Instance()->LoadTexture("res/mainmenubtn.png", "mainbutton"))
    {
        return false;
    }
    
    if(TextureManager::Instance()->LoadTexture("res/backbtn.png", "resumebutton"))
    {
        return false;
    }


    GameObject* button1 = new MenuButton(new LoaderParams(200,100,128, 96, "mainbutton"), s_pauseToMain);
    GameObject* button2 = new MenuButton(new LoaderParams(200,300,128, 96, "resumebutton"), s_resumePlay);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "entering pausestate" << std::endl;
    return true;
}

bool PauseState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TextureManager::Instance()->clearFromTextureMap("resumebutton");
    TextureManager::Instance()->clearFromTextureMap("mainbutton");
    InputHandler::Instance()->reset();
}

void PauseState::s_pauseToMain()
{
    Game::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
    Game::Instance()->getStateMachine()->popState();
}