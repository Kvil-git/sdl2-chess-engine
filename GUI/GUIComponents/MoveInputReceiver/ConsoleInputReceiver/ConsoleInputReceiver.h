#include "../MoveInputReceiverInterface/MoveInputReceiver.h"

#ifndef GUI_CONSOLEINPUTRECEIVER_H
#define GUI_CONSOLEINPUTRECEIVER_H

class ConsoleInputReceiver : public MoveInputReceiver {
    virtual int GetFromSquare() override;
    virtual int GetToSquare() override;
};

#endif