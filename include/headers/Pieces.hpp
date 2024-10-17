#ifndef _PIECES_
#define _PIECES_

#include <string>
#include "TextureManager.hpp"

#define PIECE_SIZE 80
#define OFFSET 5
#define ORIGIN_X 35
#define ORIGIN_Y 35

class Piece
{
public:
    Piece(SDL_Renderer *renderer, const std::string name);
    ~Piece();
    void setPosition(int x_index, int y_index);
    void draw();

    std::string getName() { return m_Name; }
    int getPositionX()
    {
        return pieceProperty->x;
    }
    std::string getColor()
    {
        return (m_Name[0] == 'B') ? "black" : "white";
    }

    int getPositionY()
    {
        return pieceProperty->y;
    }

    const std::string m_Name;

private:
    SDL_Renderer *m_Renderer;
    SDL_Rect *pieceProperty;
    SDL_Texture *pieceTexture;
    void init();
};

#endif