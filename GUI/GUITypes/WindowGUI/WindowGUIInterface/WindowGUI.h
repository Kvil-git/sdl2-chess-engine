#include "../../ChessGUIInterface/ChessGUI.h"
#include "../../../GUIComponents/WindowGUIOnly/WindowManager/WindowManager.h"
#include "../../../GUIComponents/WindowGUIOnly/InputStorage/InputStorage.h"

class WindowGUI : public ChessGUI {
    public:
        WindowManager& windowManager;
        InputStorage& inputStorage;

    public:
        WindowGUI(BoardRenderer& renderer, MoveInputReceiver& input) : ChessGUI(renderer, input),
              windowManager(WindowManager::GetInstance()),
              inputStorage(InputStorage::GetInstance()) {}
};