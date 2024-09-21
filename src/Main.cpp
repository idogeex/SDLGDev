#include "Game.h"

int main(int argc, char* argv[])
{
    const int FPS = 30;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    std::cout << "Game init attempt!" << std::endl;
    if(Game::Instance()->init("ProjectZero", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 640, false))
    {
        std::cout << "Game init success!" << std::endl;
        while(Game::Instance()->running())
        {
            frameStart = SDL_GetTicks();

            Game::Instance()->handleEvents();
            Game::Instance()->update();
            Game::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if(frameDelay > frameTime)
            {
                SDL_Delay(frameDelay - frameTime);
            }
        }
    }
    else
    {
        std::cout << "Game init failed :sadsmile" << SDL_GetError() << std::endl;
        return -1;
    }
    
    std::cout << "Game closing" << std::endl;
    Game::Instance()->clean();

    return 0;
}