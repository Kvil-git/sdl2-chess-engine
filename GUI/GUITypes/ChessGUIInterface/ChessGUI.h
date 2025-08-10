#ifndef GUI_CHESSGUI_H
#define GUI_CHESSGUI_H

#include "../../GUIComponents/BoardRenderer/BoardRendererInterface/BoardRenderer.h"
#include "../../GUIComponents/MoveInputReceiver/MoveInputReceiverInterface/MoveInputReceiver.h"

class ChessGUI {
    public:
        BoardRenderer& boardRenderer;
        MoveInputReceiver& moveInputReceiver;

    public:
        ChessGUI(BoardRenderer& renderer, MoveInputReceiver& input)
            : boardRenderer(renderer), moveInputReceiver(input) {}

        virtual ~ChessGUI() = default;

        virtual bool StepRender() { return true; }
        virtual void Init() {}
        virtual void Kill() {}
};

#endif