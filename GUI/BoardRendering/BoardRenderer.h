#include <string>
#include <SDL2/SDL.h>

class BoardRenderer {
    private:
        virtual void DrawBoard();
        virtual void DrawPiecesFromFEN(std::string FEN);

    public:
        virtual void RenderFEN(std::string FEN);
        virtual ~BoardRenderer();
};