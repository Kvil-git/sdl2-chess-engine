#include "../MoveInputReceiverInterface/MoveInputReceiver.h"
#include <SDL2/SDL.h>
#include "../../WindowGUIOnly/WindowManager/WindowManager.h"
#include "../../WindowGUIOnly/InputStorage/InputStorage.h"


#ifndef GUI_INPUTRECEIVER2D_H
#define GUI_INPUTRECEIVER2D_H


class InputReceiver_2D : public MoveInputReceiver {
    public:
        int GetFromSquare() override {
            InputStorage& inputStorage = InputStorage::GetInstance();
            // TODO: implement FROM square getter
            return -1;
        }
        int GetToSquare() override {
            // TODO: implement FROM to square getter
            return -1;
        }
};

#endif