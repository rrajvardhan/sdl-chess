#include <iostream>

#include <SDL2/SDL.h>

#include "Game.hpp"

const int screenWidth = 1000;
const int screenHeight = 710;

bool init()
{
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    return true;
}

void GameLoop()
{

    Game game("Chess", screenWidth, screenHeight);
    while (game.isRunning())
    {
        game.update();
    }
}

void close()
{
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char *argv[])
{

    if (!init())
    {
        std::cout << "Initialization Failed!" << std::endl;
        return 1;
    }

    GameLoop();

    close();
    return 0;
}
