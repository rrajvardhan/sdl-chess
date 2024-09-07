#include "Pieces.hpp"

void Piece::init()
{
}

Piece::Piece(SDL_Renderer *renderer, const std::string name) : m_Renderer(renderer), m_Name(name)
{
    pieceProperty = new SDL_Rect;
    pieceTexture = NULL;
    pieceProperty->w = PIECE_SIZE;
    pieceProperty->h = PIECE_SIZE;

    pieceProperty->x = ORIGIN_X;
    pieceProperty->y = ORIGIN_Y;
}

Piece::~Piece()
{
    delete pieceProperty;
    SDL_DestroyTexture(pieceTexture);
}

void Piece::setPosition(int x_index, int y_index)
{
    pieceProperty->x = (x_index) + ORIGIN_X;
    pieceProperty->y = (y_index) + ORIGIN_Y;
}

void Piece::draw()
{
    TextureManager::getInstance()->draw(m_Name, pieceProperty->x, pieceProperty->y, pieceProperty->w, pieceProperty->h, m_Renderer);
}