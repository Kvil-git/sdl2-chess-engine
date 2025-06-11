#include <string>

class BoardRenderer {
    virtual void RenderFEN(std::string FEN);
    virtual ~BoardRenderer();
};