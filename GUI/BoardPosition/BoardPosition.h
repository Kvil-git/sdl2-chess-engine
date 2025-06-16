#include <iostream>
#include <stdint.h>

#ifndef GUI_BOARDPOSITION_H
#define GUI_BOARDPOSITION_H


struct BoardPosition {
    uint8_t Pieces[8][8];
    void Output(){
        std::cout<<"position output began\n";
        for(int row=0; row<8; row++){
            for(int column=0; column<8; column++){
                std::cout<<"|"<<(int)Pieces[row][column];
                if(Pieces[row][column] < 10) std::cout<<" ";
            }
            std::cout<<"|\n";
	    }
        std::cout<<"position output ended\n";
    }
};



#endif