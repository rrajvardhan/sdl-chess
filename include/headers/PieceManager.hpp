#ifndef _PIECE_MANAGER_
#define _PIECE_MANAGER_

#include <array>
#include <vector>
#include "Board.hpp"
#include "Pieces.hpp"

namespace PIECE_TYPE
{
    const int B_P = -6;  // Black Pawn
    const int B_R = -5;  // Black Rook
    const int B_Kn = -4; // Black Knight
    const int B_B = -3;  // Black Bishop
    const int B_Q = -2;  // Black Queen
    const int B_K = -1;  // Black King
    const int EMPTY = 0; // Empty square
    const int W_P = 6;   // White Pawn
    const int W_R = 5;   // White Rook
    const int W_Kn = 4;  // White Knight
    const int W_B = 3;   // White Bishop
    const int W_Q = 2;   // White Queen
    const int W_K = 1;   // White King
}

class PieceManager
{
public:
    PieceManager(SDL_Renderer *renderer);
    ~PieceManager();

    void drawPieces();
    Piece *getPieceAtPosition(int row, int col);
    void movePiece(Piece *piece, int row, int col);
    void setSelectedPiece(Piece *piece);
    Piece *getSelectedPiece() const;
    void clearSelection();
    void setMouseHighlight(int row, int col);
    void clearMouseHighlight();
    bool isValidMove(Piece *piece, int targetRow, int targetCol);
    void calculateValidMoves(Piece *piece);
    void drawValidMoves();
    void promotePawn(Piece *pawn);
    void reset();

private:
    void initDefault();

    SDL_Renderer *m_Renderer;

    std::array<std::array<int, 8>, 8> boardPieces; // 2D array representing the board
    std::vector<Piece *> pieces;                   // Vector holding all piece objects

    Piece *selectedPiece;

    SDL_Rect mouseHighlightRect;
    bool highlightMouse;

    std::vector<std::pair<int, int>> validMoves;
};

#endif
