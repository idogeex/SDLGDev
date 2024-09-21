#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void MenuState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool MenuState::onEnter()
{
    std::cout << "menu rabotaet" << std::endl;
    if(TextureManager::Instance()->LoadTexture("res/playbtn.png", "playbutton" ))
    {
        std::cout << "obosralsya" << std::endl;
        return false;
    }
    else
    {
        std::cout << "playbtn tex rabotaet" << std::endl;
    }
    if(TextureManager::Instance()->LoadTexture("res/exitbtn.png", "exitbutton"))
    {
        std::cout << "obosralsya 2.0" << std::endl;
        return false;
    }
    else
    {
        std::cout << "exitbtn tex rabotaet" << std::endl;
    }

    GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 128, 96, "playbutton"), s_menuToPlay);
    GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 128, 96, "exitbutton"), s_exitFromMenu);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "Entering MenuState" << std::endl;
    return true;
}

bool MenuState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TextureManager::Instance()->clearFromTextureMap("playbutton");
    TextureManager::Instance()->clearFromTextureMap("exitbutton");
    TextureManager::Instance()->clearFromTextureMap("gameover1");

    std::cout << "exitiing MenuState" << std::endl;
    return true;
}

void MenuState::s_menuToPlay()
{
    std::cout << "Play button clicked" << std::endl;
    Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
    std::cout << "Clicked exit from menu" << std::endl;

    Game::Instance()->quit();
}