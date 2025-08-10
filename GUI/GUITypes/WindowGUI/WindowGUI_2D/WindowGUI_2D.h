#include "../WindowGUIInterface/WindowGUI.h"
#include "../../../GUIComponents/BoardRenderer/Renderer_2D/Renderer_2D.h"
#include "../../../GUIComponents/MoveInputReceiver/InputReceiver_2D/InputReceiver_2D.h"

class WindowGUI_2D : public WindowGUI {
    private:
        Renderer2D renderer;
        InputReceiver_2D inputReceiver;
    public:
        WindowGUI_2D() : WindowGUI(renderer, inputReceiver) {}
};