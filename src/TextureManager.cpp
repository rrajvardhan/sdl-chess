#include "TextureManager.hpp"

TextureManager* TextureManager::getInstance()
{
    static TextureManager instance;
    return &instance;
}

bool TextureManager::loadTexture(const std::string& id, const std::string& filename, SDL_Renderer* renderer)
{
    SDL_Surface* tempSurface = IMG_Load(filename.c_str());
    if (!tempSurface)
    {
        SDL_Log("Failed to load texture %s: %s", filename.c_str(), IMG_GetError());
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    if (texture)
    {
        m_TextureMap[id] = texture;
        return true;
    }

    SDL_Log("Failed to create texture from %s: %s", filename.c_str(), SDL_GetError());
    return false;
}

void TextureManager::draw(const std::string& id, int x, int y, int width, int height, SDL_Renderer* renderer)
{
    SDL_Rect srcRect = { 0, 0, width, height };
    SDL_Rect destRect = { x, y, width, height };
    SDL_RenderCopy(renderer, m_TextureMap[id], &srcRect, &destRect);
}

void TextureManager::clearTexture(const std::string& id)
{
    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);
}

TextureManager::~TextureManager()
{
    for (auto& texture : m_TextureMap)
    {
        SDL_DestroyTexture(texture.second);
    }
    m_TextureMap.clear();
}
