#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
    SDLGameObject(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

    Vector2D m_pos;
    Vector2D m_vel;
    Vector2D m_acc;
    Vector2D getPosition() { return m_pos; }

    int getWidth() { return m_width; }
    int getHeight() { return m_height; }

protected:

    int m_width;
    int m_height;

    int m_curR;
    int m_curFr;

    std::string m_texID;
};