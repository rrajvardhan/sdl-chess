#include "Board.hpp"

Board::Board(SDL_Renderer *renderer) : m_Renderer(renderer)
{
}

Board::~Board()
{
}

void Board::render()
{
    int boardSize = 710;
    int squareSize = 80;
    int offset = 35;

    TextureManager::getInstance()->draw("board_texture", 0, 0, boardSize, boardSize, m_Renderer);

    // for (int row = 0; row < 8; ++row)
    // {
    //     for (int col = 0; col < 8; ++col)
    //     {
    //         if ((row + col) % 2 == 0)
    //         {
    //             SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255); // White
    //         }
    //         else
    //         {
    //             SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255); // Black
    //         }

    //         SDL_Rect square = {offset + col * squareSize, offset + row * squareSize, squareSize, squareSize};
    //         SDL_RenderFillRect(m_Renderer, &square);
    //     }
    // }
}

void Board::update()
{
}
