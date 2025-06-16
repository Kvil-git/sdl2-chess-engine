#include "../BoardRenderer.h"
#include <SDL2/SDL.h>


#ifndef GUI_RENDERER2D_H
#define GUI_RENDERER2D_H




class Renderer2D : public BoardRenderer {
    private:
        int squareSize;
        SDL_Texture* PieceTextures[12];
        std::string PieceNames[6] = {
            "pawn", "knight", "bishop", "rook", "queen", "king"
        };

        void DrawPieceAt(int piece, SDL_Rect* destination);

        void DrawBoard(bool fromWhitePerspective = true);
        void DrawPiecesFromPosition(BoardPosition position, bool fromWhitePerspective = true);
        
    public:
        void RenderPosition(BoardPosition position, bool fromWhitePerspective = true);
        Renderer2D(int boardSquareSize = 50);
        ~Renderer2D();
};



#endif