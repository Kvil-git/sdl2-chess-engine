#include "./BoardRenderer.h"
#include <string>
#include <SDL2/SDL.h>

class Renderer2D : BoardRenderer {
    private:
        SDL_Texture* PieceTextures[12];
        std::string PieceNames[6] = {
            "pawn", "knight", "bishop", "rook", "queen", "king"
        };

        void DrawPieceAt(int piece, SDL_Rect* destination);

        
    public:
        virtual void RenderFEN(std::string FEN);
        Renderer2D();
        ~Renderer2D();
};