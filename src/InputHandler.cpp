#include "InputHandler.h"
#include "Game.h"
#include <iostream>

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler() : m_keystate(0), m_mousePosition(new Vector2D(0,0))
{
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
}

InputHandler::~InputHandler()
{
    // delete anything we created dynamically
    delete m_keystate;
    delete m_mousePosition;
    
    // clear our arrays
    m_mouseButtonStates.clear();
}

void InputHandler::reset()
{
    m_mouseButtonStates[LEFT] = false;
    m_mouseButtonStates[RIGHT] = false;
    m_mouseButtonStates[MIDDLE] = false;
}

bool InputHandler::isKeyDown(SDL_Scancode key) const
{
    if(m_keystate != 0)
    {
        if(m_keystate[key] == 1)
        {
            return true;
        } 
        else
        {
            return false;
        }
    }
    return false;
}

bool InputHandler::getMouseButtonState(int buttonNumber) const
{
    return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition() const
{
    return m_mousePosition;
}

void InputHandler::update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            Game::Instance()->quit();
        break;
        
        case SDL_MOUSEMOTION:
            onMouseMove(event);
        break;

        case SDL_MOUSEBUTTONDOWN:
            onMouseButtonDown(event);
        break;
        
        case SDL_MOUSEBUTTONUP:
            onMouseButtonUp(event);
        break;

        case SDL_KEYDOWN:
            onKeyDown();
        break;

        case SDL_KEYUP:
            onKeyUp();
        break;

        default:
        break;
        }
    }
}

void InputHandler::onKeyDown()
{
    m_keystate = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
    m_keystate = SDL_GetKeyboardState(0);
}

void InputHandler::onMouseMove(SDL_Event &event)
{
    m_mousePosition->setX(event.motion.x);
    m_mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event &event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = true;
    }
    
    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = true;
    }
    
    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = true;
    }
}

void InputHandler::onMouseButtonUp(SDL_Event &event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = false;
    }
    
    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = false;
    }
    
    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = false;
    }
}