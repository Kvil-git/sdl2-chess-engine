#ifndef MOVE_GENERATOR_CPP
#define MOVE_GENERATOR_CPP


#include "MoveGenerator.h"
#include "../../Functions/BitManipulation.h"

#include <stdint.h>
#include <vector>
#include <iostream>



using bitboard = uint64_t;






// Generate rook moves mask (excluding edges)
bitboard GenerateRookMovesMask(int sqr) {
    bitboard output = 0;
    int row = sqr / 8, col = sqr % 8;
    
    // Up (excluding edge)
    for (int r = row + 1; r < 7; r++) 
        SetBit(output, r * 8 + col);
    
    // Down (excluding edge)
    for (int r = row - 1; r > 0; r--) 
        SetBit(output, r * 8 + col);
    
    // Right (excluding edge)
    for (int c = col + 1; c < 7; c++) 
        SetBit(output, row * 8 + c);
    
    // Left (excluding edge)
    for (int c = col - 1; c > 0; c--) 
        SetBit(output, row * 8 + c);
    
    return output;
}

bitboard GenerateBishopMovesMask(int sqr) {
    bitboard output = 0;
    int row = sqr / 8, col = sqr % 8;
    
    // Down-Right (excluding edges)
    for (int r = row + 1, c = col + 1; r < 7 && c < 7; r++, c++) 
        SetBit(output, r * 8 + c);
    
    // Down-Left (excluding edges)
    for (int r = row + 1, c = col - 1; r < 7 && c > 0; r++, c--) 
        SetBit(output, r * 8 + c);
    
    // Up-Right (excluding edges)
    for (int r = row - 1, c = col + 1; r > 0 && c < 7; r--, c++) 
        SetBit(output, r * 8 + c);
    
    // Up-Left (excluding edges)
    for (int r = row - 1, c = col - 1; r > 0 && c > 0; r--, c--) 
        SetBit(output, r * 8 + c);
    
    return output;
}

// Generate actual rook attacks considering blockers
bitboard GenerateRookAttacks(int sq, bitboard blockers) {
    bitboard attacks = 0;
    int row = sq / 8, col = sq % 8;
    
    // Up
    for (int r = row + 1; r < 8; r++) {
        int target = r * 8 + col;
        SetBit(attacks, target);
        if (IsBitSet(blockers, target)) break;
    }
    // Down
    for (int r = row - 1; r >= 0; r--) {
        int target = r * 8 + col;
        SetBit(attacks, target);
        if (IsBitSet(blockers, target)) break;
    }
    // Right
    for (int c = col + 1; c < 8; c++) {
        int target = row * 8 + c;
        SetBit(attacks, target);
        if (IsBitSet(blockers, target)) break;
    }
    // Left
    for (int c = col - 1; c >= 0; c--) {
        int target = row * 8 + c;
        SetBit(attacks, target);
        if (IsBitSet(blockers, target)) break;
    }
    
    return attacks;
}

// Generate actual bishop attacks considering blockers
bitboard GenerateBishopAttacks(int sq, bitboard blockers) {
    bitboard attacks = 0;
    int row = sq / 8, col = sq % 8;
    
    // Down-right
    for (int r = row + 1, c = col + 1; r < 8 && c < 8; r++, c++) {
        int target = r * 8 + c;
        SetBit(attacks, target);
        if (IsBitSet(blockers, target)) break;
    }
    // Down-left
    for (int r = row + 1, c = col - 1; r < 8 && c >= 0; r++, c--) {
        int target = r * 8 + c;
        SetBit(attacks, target);
        if (IsBitSet(blockers, target)) break;
    }
    // Up-right
    for (int r = row - 1, c = col + 1; r >= 0 && c < 8; r--, c++) {
        int target = r * 8 + c;
        SetBit(attacks, target);
        if (IsBitSet(blockers, target)) break;
    }
    // Up-left
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
        int target = r * 8 + c;
        SetBit(attacks, target);
        if (IsBitSet(blockers, target)) break;
    }
    
    return attacks;
}

// Initialize all masks
void MoveGenerator::InitSliderPieceMasks() {
    for (int sq = 0; sq < 64; sq++) {
        RookMasks[sq] = GenerateRookMovesMask(sq);
        BishopMasks[sq] = GenerateBishopMovesMask(sq);
    }
}



// Initialize attack tables
void MoveGenerator::InitSliderMoveTables() {
    // Initialize rook attack tables
    for (int sq = 0; sq < 64; sq++) {
        if (RookMagics[sq].shift == 64) {
            // Skip if magic not found for this square
            continue;
        }
        
        bitboard mask = RookMasks[sq];
        int tableSize = RookMagics[sq].tableSize;
        RookMoves[sq].resize(tableSize, 0);
        
        // Generate all possible blocker configurations using Carry-Rippler method
        bitboard blockers = 0;
        do {
            // Calculate index using magic multiplication
            int index = (blockers * RookMagics[sq].magic) >> RookMagics[sq].shift;
            
            // Generate and store attacks for this blocker configuration
            if (index >= 0 && index < tableSize) {
                RookMoves[sq][index] = GenerateRookAttacks(sq, blockers);
            }
            
            // Get next subset of blockers
            blockers = (blockers - mask) & mask;
        } while (blockers != 0);
    }
    
    // Initialize bishop attack tables
    for (int sq = 0; sq < 64; sq++) {
        if (BishopMagics[sq].shift == 64) {
            // Skip if magic not found for this square
            continue;
        }
        
        bitboard mask = BishopMasks[sq];
        int tableSize = BishopMagics[sq].tableSize;
        BishopMoves[sq].resize(tableSize, 0);
        
        // Generate all possible blocker configurations using Carry-Rippler method
        bitboard blockers = 0;
        do {
            // Calculate index using magic multiplication
            int index = (blockers * BishopMagics[sq].magic) >> BishopMagics[sq].shift;
            
            // Generate and store attacks for this blocker configuration
            if (index >= 0 && index < tableSize) {
                BishopMoves[sq][index] = GenerateBishopAttacks(sq, blockers);
            }
            
            // Get next subset of blockers
            blockers = (blockers - mask) & mask;
        } while (blockers != 0);
    }
}

// Get rook attacks using magic bitboards
bitboard MoveGenerator::GetRookMoves(int sq, bitboard occupancy) {
    // Get relevant blockers (only those on the mask)
    bitboard blockers = occupancy & RookMasks[sq];
    
    // Calculate index using magic multiplication
    int index = (blockers * RookMagics[sq].magic) >> RookMagics[sq].shift;
    
   return RookMoves[sq][index];
}

// Get bishop attacks using magic bitboards
bitboard MoveGenerator::GetBishopMoves(int sq, bitboard occupancy) {
    // Get relevant blockers (only those on the mask)
    bitboard blockers = occupancy & BishopMasks[sq];
    
    // Calculate index using magic multiplication
    int index = (blockers * BishopMagics[sq].magic) >> BishopMagics[sq].shift;
    
    return BishopMoves[sq][index];
}




void MoveGenerator::InitKnightArrays() {
    for (int square = 0; square < 64; square++) {
        int row = square % 8;
        int column = square / 8;
        bitboard legalMoves = 0;

        // All 8 possible knight move offsets
        const int drow[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        const int dcolumn[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

        for (int increment = 0; increment < 8; increment++) {
            int newRow = row + drow[increment];
            int newColumn = column + dcolumn[increment];
            // Check if the new position is within the board
            if (newRow >= 0 && newRow < 8 && newColumn >= 0 && newColumn < 8) {
                int target_square = newColumn * 8 + newRow;
                SetBit(legalMoves, target_square);
            }
        }
        KnightMoves[square] = legalMoves;
    }
}


void MoveGenerator::InitKingArrays() {
    for(int square = 0; square < 64; square++){
        int row = square % 8;
        int column = square / 8;
        bitboard legalMoves = 0;

        // All 8 possible knight move offsets
        const int drow[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
        const int dcolumn[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

        for (int increment = 0; increment < 8; increment++) {
            int newRow = row + drow[increment];
            int newColumn = column + dcolumn[increment];
            // Check if the new position is within the board
            if (newRow >= 0 && newRow < 8 && newColumn >= 0 && newColumn < 8) {
                int target_square = newColumn * 8 + newRow;
                SetBit(legalMoves, target_square);
            }
        }
        KingMoves[square] = legalMoves;
    }
}


void MoveGenerator::InitPawnArrays() {
    for (int square = 0; square < 64; square++) {
        int row = square % 8;
        int column = square / 8;
        
        // Initialize all to zero
        PawnMoves[0][square] = 0;
        PawnMoves[1][square] = 0;
        PawnCaptures[0][square] = 0;
        PawnCaptures[1][square] = 0;
        
        // White pawn moves (advance forward)
        if (column < 7) {  // Not on the 8th rank
            SetBit(PawnCaptures[1][square], square + 8); // Single push
            
            // Double push from starting position (2nd rank)
            if (column == 1) {
                SetBit(PawnCaptures[1][square], square + 16); // Single push
            }
        }
        
        // Black pawn moves (advance forward)
        if (column > 0) {  // Not on the 1st rank
            SetBit(PawnCaptures[0][square], square - 8); // Single push
            
            // Double push from starting position (7th rank)
            if (column == 6) {
                SetBit(PawnCaptures[0][square], square - 16);
            }
        }
        
        // White pawn captures (diagonal attacks)
        if (column < 7) {  // Not on the 8th rank
            if (row > 0) {  // Not on the a-file
                SetBit(PawnCaptures[1][square], square + 7); // Left capture
            }
            if (row < 7) {  // Not on the h-file
                SetBit(PawnCaptures[1][square], square + 9); // Right capture
            }
        }
        
        // Black pawn captures (diagonal attacks)
        if (column > 0) {  // Not on the 1st rank
            if (row > 0) {  // Not on the a-file
                SetBit(PawnCaptures[0][square], square - 9); // Left capture
            }
            if (row < 7) {  // Not on the h-file
                SetBit(PawnCaptures[0][square], square - 7); // Right capture
            }
        }
    }
}


MoveGenerator::MoveGenerator(){
    InitSliderMoveTables();
    InitSliderPieceMasks();
    InitSlidingPieceArrays();
    InitKnightArrays();
    InitKingArrays();
    InitPawnArrays();
}

#endif