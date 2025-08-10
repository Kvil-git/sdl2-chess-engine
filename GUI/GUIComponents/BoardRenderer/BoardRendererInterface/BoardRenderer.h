#include "../../../GameInstances/BoardPosition/BoardPosition.h"


#ifndef GUI_BOARDRENDERER_H
#define GUI_BOARDRENDERER_H


class BoardRenderer {
    private:
        virtual void DrawBoard(bool fromWhitePerspective = true) = 0;
        virtual void DrawPiecesFromPosition(BoardPosition position, bool fromWhitePerspective = true) = 0;

    public:
        virtual void RenderPosition(BoardPosition position, bool fromWhitePerspective = true) = 0;
        virtual ~BoardRenderer() = default;
};

#endif