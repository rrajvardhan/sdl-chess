#ifndef _PIECE_MANAGER_
#define _PIECE_MANAGER_

#include <array>
#include <vector>

#include "Board.hpp"
#include "Pieces.hpp"

namespace PIECE_TYPE
{
    const int B_P = -6;
    const int B_R = -5;
    const int B_Kn = -4;
    const int B_B = -3;
    const int B_Q = -2;
    const int B_K = -1;
    //
    const int EMPTY = 0;
    //
    const int W_P = 6;
    const int W_R = 5;
    const int W_Kn = 4;
    const int W_B = 3;
    const int W_Q = 2;
    const int W_K = 1;
}

class PieceManager
{
public:
    PieceManager(SDL_Renderer *renderer);
    ~PieceManager();

    void drawPieces();

    Piece *getPieceAtPosition(int row, int col);
    void movePiece(Piece *piece, int row, int col);

    void setSelectedPiece(Piece* piece);  
    Piece* getSelectedPiece() const;     
    void clearSelection();  

    void setMouseHighlight(int row, int col); 
    void clearMouseHighlight(); 

private:
    void initDefault();

    SDL_Renderer *m_Renderer;

    std::array<std::array<int, 8>, 8> boardPieces; // 2D array representing the board
    std::vector<Piece *> pieces;                   // Vector holding all piece objects

     Piece* selectedPiece;

     SDL_Rect mouseHighlightRect;
    bool highlightMouse;
};

#endif
