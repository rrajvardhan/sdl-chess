#include "PieceManager.hpp"

void PieceManager::initDefault()
{
    boardPieces = {
        -5, -4, -3, -2, -1, -3, -4, -5,
        -6, -6, -6, -6, -6, -6, -6, -6,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        6, 6, 6, 6, 6, 6, 6, 6,
        5, 4, 3, 2, 1, 3, 4, 5};
}

PieceManager::PieceManager(SDL_Renderer *renderer) : m_Renderer(renderer)
{
    initDefault();
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            Piece *p;
            switch (boardPieces[col][row])
            {
                //black
            case PIECE_TYPE::B_R:
                p = new Piece(m_Renderer, "B_R");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;
            case PIECE_TYPE::B_Kn:
                p = new Piece(m_Renderer, "B_Kn");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;
            case PIECE_TYPE::B_B:
                p = new Piece(m_Renderer, "B_B");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;
            case PIECE_TYPE::B_Q:
                p = new Piece(m_Renderer, "B_Q");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;
            case PIECE_TYPE::B_K:
                p = new Piece(m_Renderer, "B_K");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;
            case PIECE_TYPE::B_P:
                p = new Piece(m_Renderer, "B_P");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;

                //white
                case PIECE_TYPE::W_R:
                p = new Piece(m_Renderer, "W_R");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;
            case PIECE_TYPE::W_Kn:
                p = new Piece(m_Renderer, "W_Kn");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;
            case PIECE_TYPE::W_B:
                p = new Piece(m_Renderer, "W_B");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;
            case PIECE_TYPE::W_Q:
                p = new Piece(m_Renderer, "W_Q");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;
            case PIECE_TYPE::W_K:
                p = new Piece(m_Renderer, "W_K");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;
            case PIECE_TYPE::W_P:
                p = new Piece(m_Renderer, "W_P");
                p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
                pieces.push_back(p);
                break;

            default:
                break;
            }
        }
    }
}

PieceManager::~PieceManager()
{
    for (Piece *p : pieces)
    {
        delete p;
    }
}

void PieceManager::drawPieces()
{
    for (Piece *p : pieces)
    {
        p->draw();
    }
}