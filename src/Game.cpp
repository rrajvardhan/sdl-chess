#include "Game.hpp"

void Game::init()
{
    m_Event = new SDL_Event;

    m_Window = NULL;
    m_Renderer = NULL;
    m_Running = true;
    m_Is_Selected = false;

    TextureManager::getInstance();
}

Game::Game(const char *p_Title, int p_Width, int p_Height)
{
    init();

    m_Window = SDL_CreateWindow(p_Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_Width, p_Height, SDL_WINDOW_SHOWN);
    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_PRESENTVSYNC);

    loadAssets();

    m_Board = new Board(m_Renderer);
    bpm = new PieceManager(m_Renderer);
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
    TextureManager::getInstance()->loadTexture("board_texture", "assets/boards/board_plain_03.png", m_Renderer);

    TextureManager::getInstance()->loadTexture("B_R", "assets/pieces/Black/B_R.png", m_Renderer);
    TextureManager::getInstance()->loadTexture("B_Kn", "assets/pieces/Black/B_Kn.png", m_Renderer);
    TextureManager::getInstance()->loadTexture("B_B", "assets/pieces/Black/B_B.png", m_Renderer);
    TextureManager::getInstance()->loadTexture("B_Q", "assets/pieces/Black/B_Q.png", m_Renderer);
    TextureManager::getInstance()->loadTexture("B_K", "assets/pieces/Black/B_K.png", m_Renderer);
    TextureManager::getInstance()->loadTexture("B_P", "assets/pieces/Black/B_P.png", m_Renderer);
    
    TextureManager::getInstance()->loadTexture("W_R", "assets/pieces/White/W_R.png", m_Renderer);
    TextureManager::getInstance()->loadTexture("W_Kn", "assets/pieces/White/W_Kn.png", m_Renderer);
    TextureManager::getInstance()->loadTexture("W_B", "assets/pieces/White/W_B.png", m_Renderer);
    TextureManager::getInstance()->loadTexture("W_Q", "assets/pieces/White/W_Q.png", m_Renderer);
    TextureManager::getInstance()->loadTexture("W_K", "assets/pieces/White/W_K.png", m_Renderer);
    TextureManager::getInstance()->loadTexture("W_P", "assets/pieces/White/W_P.png", m_Renderer);
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
        case SDL_MOUSEBUTTONDOWN:
            switch (m_Event->button.button)
            {
            case SDL_BUTTON_LEFT:
                m_Is_Selected = true;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            m_Is_Selected = false;
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

    if (m_Is_Selected)
        {
            int x , y ;
            SDL_GetMouseState(&x,&y);

        }

    m_Board->update();
    render();
}
void Game::render()
{
    SDL_SetRenderDrawColor(m_Renderer, 0, 255, 255, 255);
    SDL_RenderClear(m_Renderer);

    m_Board->render();

    bpm->drawPieces();


    SDL_RenderPresent(m_Renderer);
}