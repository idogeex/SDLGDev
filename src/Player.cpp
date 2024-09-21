#include "Player.h"
#include "Game.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    m_vel.setX(0);
    m_vel.setY(0);

    handleInput();
    InputHandler::Instance()->update();
    
    m_curFr = int(((SDL_GetTicks() / 150) % 5));
    m_curR = 1;
    SDLGameObject::update();
}

void Player::clean()
{

}

void Player::handleInput()
{
    Vector2D* target = InputHandler::Instance()->getMousePosition();
    m_vel = *target - m_pos;
    m_vel /= 50;

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        m_vel.setX(2);
    }
    
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        m_vel.setX(-2);
    }
    
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        m_vel.setY(-2);
    }

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        m_vel.setY(2);
    }
}