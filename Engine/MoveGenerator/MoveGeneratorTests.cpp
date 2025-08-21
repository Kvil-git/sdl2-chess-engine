#ifndef MOVE_GENERATOR_TESTS_CPP
#define MOVE_GENERATOR_TESTS_CPP

#include "MoveGenerator.h"
#include "../../Functions/BitManipulation.h"
#include <string>
#include <iostream>


void Printbitboard(bitboard bb, const std::string& title = "") {
    if (!title.empty()) {
        std::cout << title << ":\n";
    }
    
    for (int row = 7; row >= 0; row--) {
        std::cout << row + 1 << " ";
        for (int col = 0; col < 8; col++) {
            int square = row * 8 + col;
            std::cout << (IsBitSet(bb, square) ? "x " : ". ");
        }
        std::cout << "\n";
    }
    std::cout << "  a b c d e f g h\n\n";
}


#endif
