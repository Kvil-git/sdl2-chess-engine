#ifndef MOVE_GENERATOR_CPP
#define MOVE_GENERATOR_CPP


#include "MoveGenerator.h"
#include "../../Functions/BitManipulation.h"
#include "../../Enums/PlayerColors.h"

#include <stdint.h>
#include <vector>
#include <iostream>



using bitboard = uint64_t;

    struct MagicEntry {
        uint64_t magic;
        int shift;
        int tableSize;
    };


    const MagicEntry RookMagics[64] = {
        {0x0080064000201081, 52, 4096},
        {0x0040021001406000, 53, 2048},
        {0x2080200070001880, 53, 2048},
        {0x8100100100542088, 53, 2048},
        {0x8e00042008120110, 53, 2048},
        {0x4b00082400021100, 53, 2048},
        {0x02000200040800b1, 53, 2048},
        {0x0500028608402100, 52, 4096},
        {0x9800800299214000, 53, 2048},
        {0x0402002200810050, 54, 1024},
        {0x0005001045002001, 54, 1024},
        {0x0004801800d00280, 54, 1024},
        {0x002900080101504c, 54, 1024},
        {0x100d000c00880300, 54, 1024},
        {0x2023808001003a00, 54, 1024},
        {0x0101000182224100, 53, 2048},
        {0x0004808000214000, 53, 2048},
        {0x0011020049220080, 54, 1024},
        {0x6288220040108203, 54, 1024},
        {0x0222818008025002, 54, 1024},
        {0x4004008080040800, 54, 1024},
        {0x0500808012000400, 54, 1024},
        {0x4012050100020004, 54, 1024},
        {0x00000a0001840445, 53, 2048},
        {0x4200800180284002, 53, 2048},
        {0x001080a100400500, 54, 1024},
        {0x0402500480200480, 54, 1024},
        {0x2100100280080081, 54, 1024},
        {0x0048010100110c08, 54, 1024},
        {0x6000040080800200, 54, 1024},
        {0x0226088400010210, 54, 1024},
        {0x0018802680014100, 53, 2048},
        {0x3000804000801024, 53, 2048},
        {0x8110022001404008, 54, 1024},
        {0x0800500080806000, 54, 1024},
        {0x0880081042002200, 54, 1024},
        {0xa800850091000800, 54, 1024},
        {0x0101120080800400, 54, 1024},
        {0x0000100804000122, 54, 1024},
        {0x0004004286000c01, 53, 2048},
        {0x0028400280228000, 53, 2048},
        {0x0300c00081010020, 54, 1024},
        {0x4020001000858020, 54, 1024},
        {0x1002000810420020, 54, 1024},
        {0x03820020180e0010, 54, 1024},
        {0x0404040002008080, 54, 1024},
        {0x3000aa1810040015, 54, 1024},
        {0x4100010064920004, 53, 2048},
        {0x6100204008801180, 53, 2048},
        {0x010c2010004000c0, 54, 1024},
        {0x8040402003001900, 54, 1024},
        {0x0302001008224200, 54, 1024},
        {0x4201000800308700, 54, 1024},
        {0x0010800400020080, 54, 1024},
        {0x2004500208031400, 54, 1024},
        {0x0000800100005280, 53, 2048},
        {0x00a02202450080b2, 52, 4096},
        {0x808a220700401282, 53, 2048},
        {0x2200200040090011, 53, 2048},
        {0x2201000409201001, 53, 2048},
        {0x1002010c08102042, 53, 2048},
        {0x1d01000804000201, 53, 2048},
        {0x01000802011000cc, 53, 2048},
        {0x800081002088c402, 52, 4096}
    };

    const MagicEntry BishopMagics[64] = {
        {0x4040082704028010, 58, 64},
        {0x000218c813004087, 59, 32},
        {0x40849c0082004061, 59, 32},
        {0xd012408102000840, 59, 32},
        {0x00820a1000000000, 59, 32},
        {0x0201092031000000, 59, 32},
        {0x4002021082090403, 59, 32},
        {0x0001004804040a41, 58, 64},
        {0x000a292208520402, 59, 32},
        {0x008014051c250e03, 59, 32},
        {0x00501c0802014800, 59, 32},
        {0x830104104a002002, 59, 32},
        {0x0100908820201030, 59, 32},
        {0x00c0044108400214, 59, 32},
        {0x10007400a208600d, 59, 32},
        {0x0000012101105001, 59, 32},
        {0x0204082254840802, 59, 32},
        {0x1004003004088420, 59, 32},
        {0x0461120802006200, 57, 128},
        {0x0104830802004100, 57, 128},
        {0x2404028480a00000, 57, 128},
        {0x4402000088040220, 57, 128},
        {0x0082000103092189, 59, 32},
        {0x00820c0041442c00, 59, 32},
        {0x001018a4414a0400, 59, 32},
        {0x0002060650040800, 59, 32},
        {0xc0a8880010004550, 57, 128},
        {0x4008080042620020, 55, 512},
        {0x3201001081004001, 55, 512},
        {0x004040806510100c, 57, 128},
        {0x6048028201040101, 59, 32},
        {0x1000408382060100, 59, 32},
        {0x0011201005220400, 59, 32},
        {0x090082100c200404, 59, 32},
        {0x3020402800100d40, 57, 128},
        {0x0082008400020120, 55, 512},
        {0x00040100700c00c0, 55, 512},
        {0x8210204080011004, 57, 128},
        {0x0f07020600041100, 59, 32},
        {0x0003040020408210, 59, 32},
        {0xea0c023842002c10, 59, 32},
        {0x0494012410014a01, 59, 32},
        {0x2017004022003004, 57, 128},
        {0x0002401414000800, 57, 128},
        {0x4404400091000200, 57, 128},
        {0x0624008401008810, 57, 128},
        {0x0d0210060a000280, 59, 32},
        {0x0104440042000040, 59, 32},
        {0x0002080212d08000, 59, 32},
        {0x0001410828220024, 59, 32},
        {0x000000c200d01c20, 59, 32},
        {0x00000000840c2000, 59, 32},
        {0x000264080b040040, 59, 32},
        {0x0018604431020470, 59, 32},
        {0x0140022881010414, 59, 32},
        {0x508810118a004981, 59, 32},
        {0x8400841101012012, 58, 64},
        {0x2020008205b00400, 59, 32},
        {0xc010071042080400, 59, 32},
        {0x00044080649c0400, 59, 32},
        {0x0090502051120202, 59, 32},
        {0x2002002002060a00, 59, 32},
        {0xf010905050008284, 59, 32},
        {0x00848804b8018100, 58, 64}
    };



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




const bitboard CastlingMasks[2][2] = {
    {0x60, 0xe}, {0x6000000000000000, 0xe00000000000000}
};
//white king castled from e1 to either g1 or c1, black king from e8 to g8 or c8 
const Move KingCastlingMoves[2][2] = {
    {Move(4, 6), Move(4, 2)}, {Move(60, 62), Move(60, 58)}
};

std::vector<Move> MoveGenerator::GenerateCastlingMoves(const Board& board, bool sideToMove){
    std::vector<Move> output;
    for(int castlingType = 0; castlingType < 2; castlingType++){
        
        if(board.castlingRights[sideToMove][castlingType] == false) continue;

        // if there are pieces present between rook and king, continue
        if((CastlingMasks[sideToMove][castlingType] & board.AllPieces) != 0) continue;

        output.push_back(KingCastlingMoves[sideToMove][castlingType]);
    }

    return output;
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