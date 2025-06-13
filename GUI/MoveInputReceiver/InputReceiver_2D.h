#include "MoveInputReceiver.h"
#include <SDL2/SDL.h>
#include "../WindowManager/WindowManager.h"
#include "../InputStorage/InputStorage.h"

class InputReceiver_2D : MoveInputReceiver{
    int GetFromSquare() {
        InputStorage& inputStorage = InputStorage::GetInstance();
        
    };
    int GetToSquare();
};