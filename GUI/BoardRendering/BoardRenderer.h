#include <string>
#include <SDL2/SDL.h>

class BoardRenderer {
    SDL_Window* window;
    SDL_Renderer* renderer;

    virtual void RenderFEN(std::string FEN);
    virtual ~BoardRenderer();
};