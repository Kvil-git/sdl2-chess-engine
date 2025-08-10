#include "../MoveInputReceiverInterface/MoveInputReceiver.h"
#include <SDL2/SDL.h>
#include "../../WindowGUIOnly/WindowManager/WindowManager.h"
#include "../../WindowGUIOnly/InputStorage/InputStorage.h"


#ifndef GUI_INPUTRECEIVER3D_H
#define GUI_INPUTRECEIVER3D_H

class InputReceiver_3D : MoveInputReceiver{
    int GetFromSquare();
    int GetToSquare();
};

#endif