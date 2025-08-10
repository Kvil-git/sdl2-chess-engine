#include <iostream>



#ifndef GUI_MOVEINPUTRECEIVER_H
#define GUI_MOVEINPUTRECEIVER_H

class MoveInputReceiver {
    public:
        virtual int GetFromSquare() = 0;
        virtual int GetToSquare() = 0;

        virtual ~MoveInputReceiver() = default;
};


#endif