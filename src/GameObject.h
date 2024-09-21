#pragma once
#include <string>
#include <iostream>
#include "LoaderParams.h"
#include "InputHandler.h"

class GameObject
{
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
protected:

    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
};