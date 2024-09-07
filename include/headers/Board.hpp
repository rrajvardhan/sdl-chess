#ifndef BOARD_HPP
#define BOARD_HPP

#include <SDL2/SDL.h>

#include "TextureManager.hpp"

class Board
{
public:
    Board(SDL_Renderer* renderer);
    ~Board();

    void render(); 
    void update(); 

private:
    SDL_Renderer* m_Renderer;
};

#endif
