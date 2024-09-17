#include "PieceManager.hpp"
#include <iostream>

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

void PieceManager::reset()
{
    std::cout << "reseting pieces" << std::endl;
    boardPieces = {
        -5, -4, -3, -2, -1, -3, -4, -5,
        -6, -6, -6, -6, -6, -6, -6, -6,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        6, 6, 6, 6, 6, 6, 6, 6,
        5, 4, 3, 2, 1, 3, 4, 5};

    // Clear and reinitialize the pieces
    for (Piece *p : pieces)
    {
        delete p;
    }
    pieces.clear();

    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            Piece *p;
            switch (boardPieces[col][row])
            {
            case PIECE_TYPE::B_R:
                p = new Piece(m_Renderer, "B_R");
                break;
            case PIECE_TYPE::B_Kn:
                p = new Piece(m_Renderer, "B_Kn");
                break;
            case PIECE_TYPE::B_B:
                p = new Piece(m_Renderer, "B_B");
                break;
            case PIECE_TYPE::B_Q:
                p = new Piece(m_Renderer, "B_Q");
                break;
            case PIECE_TYPE::B_K:
                p = new Piece(m_Renderer, "B_K");
                break;
            case PIECE_TYPE::B_P:
                p = new Piece(m_Renderer, "B_P");
                break;
            case PIECE_TYPE::W_R:
                p = new Piece(m_Renderer, "W_R");
                break;
            case PIECE_TYPE::W_Kn:
                p = new Piece(m_Renderer, "W_Kn");
                break;
            case PIECE_TYPE::W_B:
                p = new Piece(m_Renderer, "W_B");
                break;
            case PIECE_TYPE::W_Q:
                p = new Piece(m_Renderer, "W_Q");
                break;
            case PIECE_TYPE::W_K:
                p = new Piece(m_Renderer, "W_K");
                break;
            case PIECE_TYPE::W_P:
                p = new Piece(m_Renderer, "W_P");
                break;
            default:
                continue;
            }
            p->setPosition(row * PIECE_SIZE, col * PIECE_SIZE);
            pieces.push_back(p);
        }
    }
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
                // black
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

            // white
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
            SDL_SetRenderDrawColor(m_Renderer, 36, 40, 59, 1);
            SDL_Rect highlightRect = {
                p->getPositionX(),
                p->getPositionY(),
                PIECE_SIZE,
                PIECE_SIZE};
            SDL_RenderFillRect(m_Renderer, &highlightRect);
        }

        p->draw();
    }
}

Piece *PieceManager::getPieceAtPosition(int row, int col)
{
    int pieceType = boardPieces[row][col];

    if (pieceType == 0)
    {
        return nullptr;
    }

    std::string pieceName;
    switch (pieceType)
    {
    case PIECE_TYPE::B_R:
        pieceName = "B_R";
        break;
    case PIECE_TYPE::B_Kn:
        pieceName = "B_Kn";
        break;
    case PIECE_TYPE::B_B:
        pieceName = "B_B";
        break;
    case PIECE_TYPE::B_Q:
        pieceName = "B_Q";
        break;
    case PIECE_TYPE::B_K:
        pieceName = "B_K";
        break;
    case PIECE_TYPE::B_P:
        pieceName = "B_P";
        break;
    case PIECE_TYPE::W_R:
        pieceName = "W_R";
        break;
    case PIECE_TYPE::W_Kn:
        pieceName = "W_Kn";
        break;
    case PIECE_TYPE::W_B:
        pieceName = "W_B";
        break;
    case PIECE_TYPE::W_Q:
        pieceName = "W_Q";
        break;
    case PIECE_TYPE::W_K:
        pieceName = "W_K";
        break;
    case PIECE_TYPE::W_P:
        pieceName = "W_P";
        break;
    default:
        return nullptr;
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

void PieceManager::movePiece(Piece *piece, int newRow, int newCol)
{
    int oldRow = piece->getPositionY() / PIECE_SIZE;
    int oldCol = piece->getPositionX() / PIECE_SIZE;

    std::string pieceName = piece->getName();
    int pieceType = 0;

    if (pieceName == "B_R")
        pieceType = PIECE_TYPE::B_R;
    else if (pieceName == "B_Kn")
        pieceType = PIECE_TYPE::B_Kn;
    else if (pieceName == "B_B")
        pieceType = PIECE_TYPE::B_B;
    else if (pieceName == "B_Q")
        pieceType = PIECE_TYPE::B_Q;
    else if (pieceName == "B_K")
        pieceType = PIECE_TYPE::B_K;
    else if (pieceName == "B_P")
        pieceType = PIECE_TYPE::B_P;
    else if (pieceName == "W_R")
        pieceType = PIECE_TYPE::W_R;
    else if (pieceName == "W_Kn")
        pieceType = PIECE_TYPE::W_Kn;
    else if (pieceName == "W_B")
        pieceType = PIECE_TYPE::W_B;
    else if (pieceName == "W_Q")
        pieceType = PIECE_TYPE::W_Q;
    else if (pieceName == "W_K")
        pieceType = PIECE_TYPE::W_K;
    else if (pieceName == "W_P")
        pieceType = PIECE_TYPE::W_P;

    // Capture the opponent's piece if present
    int targetPieceType = boardPieces[newRow][newCol];
    if (targetPieceType != 0 && ((pieceType > 0 && targetPieceType < 0) || (pieceType < 0 && targetPieceType > 0)))
    {
        // Remove the opponent's piece from the board
        for (auto it = pieces.begin(); it != pieces.end(); ++it)
        {
            Piece *p = *it;
            if (p->getPositionY() / PIECE_SIZE == newRow && p->getPositionX() / PIECE_SIZE == newCol)
            {
                delete p;
                pieces.erase(it);
                break;
            }
        }
    }

    boardPieces[oldRow][oldCol] = 0;         // Clear the old position
    boardPieces[newRow][newCol] = pieceType; // Set the new position

    piece->setPosition(newCol * PIECE_SIZE, newRow * PIECE_SIZE);

    // Pawn promotion check
    // TODO: pawn promotion options
    if (pieceName == "W_P" && newRow == 0)
    {
        promotePawn(piece);
    }
    else if (pieceName == "B_P" && newRow == 7)
    {
        promotePawn(piece);
    }
    else
    {
        piece->setPosition(newCol * PIECE_SIZE, newRow * PIECE_SIZE);
    }

    selectedPiece = nullptr;
}

/*
void PieceManager::promotePawn(Piece *pawn, const std::string &promotionPieceName)
{
    int row = pawn->getPositionY() / PIECE_SIZE;
    int col = pawn->getPositionX() / PIECE_SIZE;

    // Remove the pawn from the board
    boardPieces[row][col] = 0;

    // Create the promoted piece
    Piece *promotedPiece = new Piece(m_Renderer, promotionPieceName);
    promotedPiece->setPosition(col * PIECE_SIZE, row * PIECE_SIZE);

    // Add the promoted piece to the board
    boardPieces[row][col] = (promotionPieceName == "W_Q") ? PIECE_TYPE::W_Q : PIECE_TYPE::B_Q;

    // Update the pieces list
    for (auto it = pieces.begin(); it != pieces.end(); ++it)
    {
        if (*it == pawn)
        {
            delete pawn;
            pieces.erase(it);
            break;
        }
    }
    pieces.push_back(promotedPiece);
}
*/

void PieceManager::promotePawn(Piece *pawn)
{
    int row = pawn->getPositionY() / PIECE_SIZE;
    int col = pawn->getPositionX() / PIECE_SIZE;
    
    int x = ORIGIN_X;
    int y = 160 + ORIGIN_Y;

    SDL_Rect queenRect = {x, y, PIECE_SIZE, PIECE_SIZE};
    SDL_Rect rookRect = {x, y +80, PIECE_SIZE, PIECE_SIZE};
    SDL_Rect bishopRect = {x , y+160, PIECE_SIZE, PIECE_SIZE};
    SDL_Rect knightRect = {x, y+240, PIECE_SIZE, PIECE_SIZE};

    SDL_SetRenderDrawColor(m_Renderer, 180, 180, 180, 255);

    SDL_RenderFillRect(m_Renderer, &queenRect);
    SDL_RenderFillRect(m_Renderer, &rookRect);
    SDL_RenderFillRect(m_Renderer, &bishopRect);
    SDL_RenderFillRect(m_Renderer, &knightRect);

    TextureManager::getInstance()->draw((row == 0 ? "W_Q" : "B_Q"), queenRect.x,queenRect.y,queenRect.w,queenRect.h,m_Renderer);
    TextureManager::getInstance()->draw((row == 0 ? "W_R" : "B_R"), rookRect.x,rookRect.y,rookRect.w,rookRect.h,m_Renderer);
    TextureManager::getInstance()->draw((row == 0 ? "W_B" : "B_B"), bishopRect.x,bishopRect.y,bishopRect.w,bishopRect.h,m_Renderer);
    TextureManager::getInstance()->draw((row == 0 ? "W_Kn" : "B_Kn"), knightRect.x,knightRect.y,knightRect.w,knightRect.h,m_Renderer);

    SDL_RenderPresent(m_Renderer);
    SDL_Event e;
    bool promotionDone = false;

    while (!promotionDone)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_Point mousePos = {e.button.x, e.button.y};

                if (SDL_PointInRect(&mousePos, &queenRect))
                {
                    Piece *promotedPiece = new Piece(m_Renderer, (row == 0 ? "W_Q" : "B_Q"));
                    promotedPiece->setPosition(col * PIECE_SIZE, row * PIECE_SIZE);
                    boardPieces[row][col] = (row == 0 ? PIECE_TYPE::W_Q : PIECE_TYPE::B_Q);
                    pieces.push_back(promotedPiece);
                    promotionDone = true;
                }
                else if (SDL_PointInRect(&mousePos, &rookRect))
                {
                    Piece *promotedPiece = new Piece(m_Renderer, (row == 0 ? "W_R" : "B_R"));
                    promotedPiece->setPosition(col * PIECE_SIZE, row * PIECE_SIZE);
                    boardPieces[row][col] = (row == 0 ? PIECE_TYPE::W_R : PIECE_TYPE::B_R);
                    pieces.push_back(promotedPiece);
                    promotionDone = true;
                }
                else if (SDL_PointInRect(&mousePos, &bishopRect))
                {
                    Piece *promotedPiece = new Piece(m_Renderer, (row == 0 ? "W_B" : "B_B"));
                    promotedPiece->setPosition(col * PIECE_SIZE, row * PIECE_SIZE);
                    boardPieces[row][col] = (row == 0 ? PIECE_TYPE::W_B : PIECE_TYPE::B_B);
                    pieces.push_back(promotedPiece);
                    promotionDone = true;
                }
                else if (SDL_PointInRect(&mousePos, &knightRect))
                {
                    Piece *promotedPiece = new Piece(m_Renderer, (row == 0 ? "W_Kn" : "B_Kn"));
                    promotedPiece->setPosition(col * PIECE_SIZE, row * PIECE_SIZE);
                    boardPieces[row][col] = (row == 0 ? PIECE_TYPE::W_Kn : PIECE_TYPE::B_Kn);
                    pieces.push_back(promotedPiece);
                    promotionDone = true;
                }
            }
        }
    }

    for (auto it = pieces.begin(); it != pieces.end(); ++it)
    {
        if (*it == pawn)
        {
            delete pawn;
            pieces.erase(it);
            break;
        }
    }
}

void PieceManager::setSelectedPiece(Piece *piece)
{
    selectedPiece = piece;
}

Piece *PieceManager::getSelectedPiece() const
{
    return selectedPiece;
}

void PieceManager::clearSelection()
{
    selectedPiece = nullptr;
    validMoves.clear();
}

void PieceManager::setMouseHighlight(int row, int col)
{
    if (row >= 8 || col >= 8)
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

void PieceManager::calculateValidMoves(Piece *piece)
{
    validMoves.clear();

    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if (isValidMove(piece, row, col))
            {
                validMoves.push_back(std::make_pair(row, col));
            }
        }
    }
}

void PieceManager::drawValidMoves()
{
    SDL_SetRenderDrawColor(m_Renderer, 37, 40, 59, 255);

    for (const auto &move : validMoves)
    {
        SDL_Rect rect;
        int dotSize = PIECE_SIZE * 1;
        rect.w = dotSize;
        rect.h = dotSize;

        rect.x = move.second * PIECE_SIZE + ORIGIN_X + (PIECE_SIZE - dotSize) / 2;
        rect.y = move.first * PIECE_SIZE + ORIGIN_Y + (PIECE_SIZE - dotSize) / 2;

        SDL_RenderFillRect(m_Renderer, &rect);
    }
}

bool PieceManager::isValidMove(Piece *piece, int targetRow, int targetCol)
{
    int currentRow = piece->getPositionY() / PIECE_SIZE;
    int currentCol = piece->getPositionX() / PIECE_SIZE;

    std::string pieceName = piece->getName();

    // General move validation
    if (targetRow < 0 || targetRow >= 8 || targetCol < 0 || targetCol >= 8)
    {
        return false; // Out of bounds
    }

    // Check if the target square is occupied by the same color
    if (boardPieces[targetRow][targetCol] != 0 &&
        (boardPieces[targetRow][targetCol] > 0 && pieceName[0] == 'W' ||
         boardPieces[targetRow][targetCol] < 0 && pieceName[0] == 'B'))
    {
        return false;
    }

    if (pieceName == "W_P" || pieceName == "B_P") // Pawn
    {
        int direction = (pieceName == "W_P") ? -1 : 1;

        // Forward move
        if (currentCol == targetCol && boardPieces[targetRow][targetCol] == 0)
        {
            if (targetRow == currentRow + direction)
            {
                return true;
            }
            if ((currentRow == 1 || currentRow == 6) && targetRow == currentRow + 2 * direction && boardPieces[currentRow + direction][currentCol] == 0)
            {
                return true;
            }
        }

        // Diagonal capture
        if ((targetCol == currentCol - 1 || targetCol == currentCol + 1) && targetRow == currentRow + direction && boardPieces[targetRow][targetCol] != 0)
        {
            int targetPiece = boardPieces[targetRow][targetCol];
            if ((pieceName == "W_P" && targetPiece < 0) || (pieceName == "B_P" && targetPiece > 0))
            {
                return true;
            }
        }
    }
    else if (pieceName == "W_R" || pieceName == "B_R") // Rook
    {
        if (currentRow == targetRow || currentCol == targetCol)
        {
            int rowStep = (currentRow == targetRow) ? 0 : (currentRow < targetRow ? 1 : -1);
            int colStep = (currentCol == targetCol) ? 0 : (currentCol < targetCol ? 1 : -1);
            int r = currentRow + rowStep;
            int c = currentCol + colStep;
            while (r != targetRow || c != targetCol)
            {
                if (boardPieces[r][c] != 0)
                {
                    return false;
                }
                r += rowStep;
                c += colStep;
            }
            return true;
        }
    }
    else if (pieceName == "W_Q" || pieceName == "B_Q") // Queen
    {
        if (currentRow == targetRow || currentCol == targetCol) // Rook-like move
        {
            if (currentRow == targetRow || currentCol == targetCol)
            {
                int rowStep = (currentRow == targetRow) ? 0 : (currentRow < targetRow ? 1 : -1);
                int colStep = (currentCol == targetCol) ? 0 : (currentCol < targetCol ? 1 : -1);
                int r = currentRow + rowStep;
                int c = currentCol + colStep;
                while (r != targetRow || c != targetCol)
                {
                    if (boardPieces[r][c] != 0)
                    {
                        return false;
                    }
                    r += rowStep;
                    c += colStep;
                }
                return true;
            }
        }
        else if (abs(targetRow - currentRow) == abs(targetCol - currentCol)) // Bishop-like move
        {
            int rowStep = (targetRow > currentRow) ? 1 : -1;
            int colStep = (targetCol > currentCol) ? 1 : -1;
            int r = currentRow + rowStep;
            int c = currentCol + colStep;
            while (r != targetRow && c != targetCol)
            {
                if (boardPieces[r][c] != 0)
                {
                    return false;
                }
                r += rowStep;
                c += colStep;
            }
            return true;
        }
    }
    else if (pieceName == "W_Kn" || pieceName == "B_Kn") // Knight
    {
        int rowDiff = abs(targetRow - currentRow);
        int colDiff = abs(targetCol - currentCol);
        if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2))
        {
            return true;
        }
    }
    else if (pieceName == "W_B" || pieceName == "B_B") // Bishop
    {
        if (abs(targetRow - currentRow) == abs(targetCol - currentCol))
        {
            int rowStep = (targetRow > currentRow) ? 1 : -1;
            int colStep = (targetCol > currentCol) ? 1 : -1;
            int r = currentRow + rowStep;
            int c = currentCol + colStep;
            while (r != targetRow && c != targetCol)
            {
                if (boardPieces[r][c] != 0)
                {
                    return false;
                }
                r += rowStep;
                c += colStep;
            }
            return true;
        }
    }
    else if (pieceName == "W_K" || pieceName == "B_K") // King
    {
        if (abs(targetRow - currentRow) <= 1 && abs(targetCol - currentCol) <= 1)
        {
            return true;
        }
    }

    return false;
}
