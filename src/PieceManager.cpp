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

PieceManager::PieceManager(SDL_Renderer *renderer) : m_Renderer(renderer), selectedPiece(nullptr)
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
    if (highlightMouse)
    {
        SDL_SetRenderDrawColor(m_Renderer, 105, 105, 105, 105); 
        SDL_RenderFillRect(m_Renderer, &mouseHighlightRect);
    }
    
    for (Piece *p : pieces)
    {
        if (p == selectedPiece)
        {
            SDL_SetRenderDrawColor(m_Renderer, 255, 235, 65, 255);
            SDL_Rect highlightRect = {
                p->getPositionX(),
                p->getPositionY(),
                PIECE_SIZE ,
                PIECE_SIZE 
            };
            SDL_RenderFillRect(m_Renderer, &highlightRect);
        }

        p->draw();
    }
    
}

Piece* PieceManager::getPieceAtPosition(int row, int col)
{
    int pieceType = boardPieces[row][col]; 

    if (pieceType == 0) 
    {
        return nullptr;
    }

    std::string pieceName;
    switch (pieceType)
    {
        case PIECE_TYPE::B_R: pieceName = "B_R"; break;
        case PIECE_TYPE::B_Kn: pieceName = "B_Kn"; break;
        case PIECE_TYPE::B_B: pieceName = "B_B"; break;
        case PIECE_TYPE::B_Q: pieceName = "B_Q"; break;
        case PIECE_TYPE::B_K: pieceName = "B_K"; break;
        case PIECE_TYPE::B_P: pieceName = "B_P"; break;
        case PIECE_TYPE::W_R: pieceName = "W_R"; break;
        case PIECE_TYPE::W_Kn: pieceName = "W_Kn"; break;
        case PIECE_TYPE::W_B: pieceName = "W_B"; break;
        case PIECE_TYPE::W_Q: pieceName = "W_Q"; break;
        case PIECE_TYPE::W_K: pieceName = "W_K"; break;
        case PIECE_TYPE::W_P: pieceName = "W_P"; break;
        default: return nullptr;
    }

    for (Piece *p : pieces)
    {
        if (p->getName() == pieceName)
        {
            int pieceRow = p->getPositionY() / PIECE_SIZE;
            int pieceCol = p->getPositionX() / PIECE_SIZE;

            if (pieceRow == row && pieceCol == col)
            {
                return p;
            }
        }
    }
    return nullptr;
}

void PieceManager::movePiece(Piece* piece, int newRow, int newCol)
{
    int oldRow = piece->getPositionY() / PIECE_SIZE;
    int oldCol = piece->getPositionX() / PIECE_SIZE;

    std::string pieceName = piece->getName();
    int pieceType = 0;

    if (pieceName == "B_R") pieceType = PIECE_TYPE::B_R;
    else if (pieceName == "B_Kn") pieceType = PIECE_TYPE::B_Kn;
    else if (pieceName == "B_B") pieceType = PIECE_TYPE::B_B;
    else if (pieceName == "B_Q") pieceType = PIECE_TYPE::B_Q;
    else if (pieceName == "B_K") pieceType = PIECE_TYPE::B_K;
    else if (pieceName == "B_P") pieceType = PIECE_TYPE::B_P;
    else if (pieceName == "W_R") pieceType = PIECE_TYPE::W_R;
    else if (pieceName == "W_Kn") pieceType = PIECE_TYPE::W_Kn;
    else if (pieceName == "W_B") pieceType = PIECE_TYPE::W_B;
    else if (pieceName == "W_Q") pieceType = PIECE_TYPE::W_Q;
    else if (pieceName == "W_K") pieceType = PIECE_TYPE::W_K;
    else if (pieceName == "W_P") pieceType = PIECE_TYPE::W_P;

    boardPieces[oldRow][oldCol] = 0; // Clear the old position
    boardPieces[newRow][newCol] = pieceType; // Set the new position

    piece->setPosition(newCol * PIECE_SIZE, newRow * PIECE_SIZE);

    selectedPiece = nullptr;
}

void PieceManager::setSelectedPiece(Piece* piece)
{
    selectedPiece = piece;
}

Piece* PieceManager::getSelectedPiece() const
{
    return selectedPiece;
}

void PieceManager::clearSelection()
{
    selectedPiece = nullptr;
}


void PieceManager::setMouseHighlight(int row, int col)
{
    if(row >=8 || col >= 8)
    {
        highlightMouse = false;
        return;
    }

    highlightMouse = true;
    mouseHighlightRect.x = col * PIECE_SIZE + ORIGIN_X;
    mouseHighlightRect.y = row * PIECE_SIZE + ORIGIN_Y;
    mouseHighlightRect.w = PIECE_SIZE;
    mouseHighlightRect.h = PIECE_SIZE;
}

void PieceManager::clearMouseHighlight()
{
    highlightMouse = false;
}
