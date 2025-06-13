#include <string>
#include <SDL2/SDL.h>
#include "../BoardPosition/BoardPosition.h"
class BoardRenderer {
    private:
        virtual void DrawBoard();
        virtual void DrawPiecesFromPosition(BoardPosition position);

    public:
        virtual void RenderPosition(BoardPosition position);
        virtual ~BoardRenderer();
};