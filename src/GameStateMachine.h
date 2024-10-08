#pragma once
#include "GameState.h"
#include <vector>

class GameStateMachine
{
public:
    void update();
    void render();

    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();
private:
    std::vector<GameState*> m_gameStates;
};