#ifndef _GAME_
#define _GAME_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "TextureManager.hpp"
#include "Board.hpp"
#include "Pieces.hpp"

class Game
{
public:
    Game(const char *p_Title, int p_Width, int p_Height);
    ~Game();

    void update();
    bool isRunning();
    void render();
    void pollEvent();

private:
    void init();
    void loadAssets();
    bool m_Running = false;
    SDL_Window *m_Window;
    SDL_Renderer *m_Renderer;

    SDL_Event *m_Event;

    Board *m_Board;
    Piece* m_bP;   
};

#endif