#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>

class TextureManager
{
public:
    static TextureManager* getInstance(); // Singleton pattern

    bool loadTexture(const std::string& id, const std::string& filename, SDL_Renderer* renderer);
    void draw(const std::string& id, int x, int y, int width, int height, SDL_Renderer* renderer);
    void clearTexture(const std::string& id);

    ~TextureManager();

private:
    TextureManager() = default; // Private constructor for singleton

    std::map<std::string, SDL_Texture*> m_TextureMap; // Map to store textures
};

#endif
