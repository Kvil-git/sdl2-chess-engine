#include <iostream>
#include <stdint.h>

#include "../Enums/PieceType.h"

#ifndef GUI_BOARDARRAY_H
#define GUI_BOARDARRAY_H



struct BoardArray {
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

    BoardArray(){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                Pieces[i][j] = static_cast<int>(ChessPiece::NONE);
            }
        }
    }

};




#endif