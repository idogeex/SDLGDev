#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
    m_vel.setY(2);
    m_vel.setX(0.001);
}

void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::update()
{
    m_curFr = int(((SDL_GetTicks() / 100) % 5));

    if(m_pos.getY() < 0)
    {
        m_vel.setY(2);
    }
    else if (m_pos.getY() > 400)
    {
        m_vel.setY(-2);
    }

    SDLGameObject::update();
}

void Enemy::clean()
{

}