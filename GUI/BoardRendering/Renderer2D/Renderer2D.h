#include "./BoardRenderer.h"
#include <string>

class Renderer2D : BoardRenderer {
    virtual void RenderFEN(std::string FEN);
    Renderer2D();
    ~Renderer2D();
};