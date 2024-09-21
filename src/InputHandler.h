#pragma once

#include <vector>

#include <SDL2/SDL.h>
#include "Vector2D.h"

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler
{
public:
    static InputHandler* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }

    void update();
    void reset();
    bool isKeyDown(SDL_Scancode key) const;

    bool getMouseButtonState(int buttonNumber) const;

    Vector2D* getMousePosition() const;

private: 
    InputHandler();
    ~InputHandler();

    // handle keyboard events
    void onKeyDown();
    void onKeyUp();
    const Uint8* m_keystate;

    //handle mouse events
    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);

    //mouse specific
    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;

    static InputHandler* s_pInstance;
};