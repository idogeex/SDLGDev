#include "MenuButton.h"
#include "Game.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams* pParams, void (*callback) ()) : SDLGameObject(pParams), m_callback(callback)
{
    m_curFr = MOUSE_OUT;
    m_curR = 1;
}

void MenuButton::draw()
{
    SDLGameObject::draw();
}

void MenuButton::update()
{
    Vector2D* pMousePos = InputHandler::Instance()->getMousePosition();
    
    if(pMousePos->getX() < (m_pos.getX() + m_width)
    && pMousePos->getX() > m_pos.getX() 
    && pMousePos->getY() < (m_pos.getY() + m_height)
    && pMousePos->getY() > m_pos.getY())
    {
        if(InputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
        {
            m_curFr = CLICKED;
            m_callback();
            m_bReleased = false;
        }
        else if(!InputHandler::Instance()->getMouseButtonState(LEFT))
        {
            m_bReleased = true;
            m_curFr = MOUSE_OVER;
        }
    }
    
    else 
    {
        m_curFr = MOUSE_OUT;
    }
    
}

void MenuButton::clean()
{
}