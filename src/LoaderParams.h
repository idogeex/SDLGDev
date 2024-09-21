#pragma once  
#include <string> 

class LoaderParams
{
public:

    LoaderParams(int x, int y, int width, int height, std::string texID) : m_x(x), m_y(y), m_width(width), m_height(height), m_texID(texID)
    {

    }

    int getX() const {return m_x;}
    int getY() const {return m_y;}
    int getW() const {return m_width;}
    int getH() const {return m_height;}
    std::string getTexID() const {return m_texID;}
 
private:
    int m_x;
    int m_y;

    int m_width;
    int m_height;

    std::string m_texID;
};