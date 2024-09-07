#include "Game.hpp"

void Game::init()
{
    m_Event = new SDL_Event;

    m_Window = NULL;
    m_Renderer = NULL;
    m_Running = true;

    TextureManager::getInstance();
}

Game::Game(const char *p_Title, int p_Width, int p_Height)
{
    init();

    m_Window = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_Width, p_Height, SDL_WINDOW_SHOWN);
    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_PRESENTVSYNC);

    loadAssets();

    m_Board = new Board(m_Renderer);
    m_bP = new Piece(m_Renderer, "B_P");
}

Game::~Game()
{
    delete m_Event;
    delete m_Board;
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
}

void Game::loadAssets()
{
    TextureManager::getInstance()->loadTexture("board_texture", "assets/boards/board_plain_01.png", m_Renderer);

    TextureManager::getInstance()->loadTexture("B_P", "assets/pieces/Black/B_Q.png", m_Renderer);
}

void Game::pollEvent()
{
    while (SDL_PollEvent(m_Event))
    {
        switch (m_Event->type)
        {
        case SDL_QUIT:
            m_Running = false;
            break;
        }
    }
}

bool Game::isRunning()
{
    return m_Running;
}
void Game::update()
{
    pollEvent();
    m_Board->update();
    render();
}
void Game::render()
{
    SDL_SetRenderDrawColor(m_Renderer, 0, 255, 255, 255);
    SDL_RenderClear(m_Renderer);

    m_Board->render();

    m_bP->draw();
    m_bP->setPosition(4, 4);

    SDL_RenderPresent(m_Renderer);
}