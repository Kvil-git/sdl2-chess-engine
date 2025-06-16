#include <iostream>



#ifndef GUI_MOUSEINPUTRECEIVER_H
#define GUI_MOUSEINPUTRECEIVER_H

class MoveInputReceiver {
    virtual int GetFromSquare();
    virtual int GetToSquare();
};


#endif