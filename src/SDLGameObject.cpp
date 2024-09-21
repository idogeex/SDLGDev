#include "SDLGameObject.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), m_pos(pParams->getX(), pParams->getY()), m_vel(0, 0), m_acc(0, 0)
{
    m_width = pParams->getW();
    m_height = pParams->getH();
    m_texID = pParams->getTexID();

    m_curR = 1;
    m_curFr = 0;
}

void SDLGameObject::draw()
{
    if(m_vel.getX() > 0)
    {
        TextureManager::Instance()->drawFrame(m_texID, (Uint32)m_pos.getX(), (Uint32)m_pos.getY(), m_width, m_height, m_curR, m_curFr, Game::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
    }
    else
    {
        TextureManager::Instance()->drawFrame(m_texID, (Uint32)m_pos.getX(), (Uint32)m_pos.getY(), m_width, m_height, m_curR, m_curFr, Game::Instance()->getRenderer());
    }
}

void SDLGameObject::update()
{
    m_vel += m_acc;
    m_pos += m_vel;
}

void SDLGameObject::clean()
{

}