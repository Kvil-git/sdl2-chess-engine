#ifndef MOVE_GENERATOR_TESTS_CPP
#define MOVE_GENERATOR_TESTS_CPP

#include "../../Engine/MoveGenerator/MoveGenerator.h"
#include "../../Functions/BitManipulation.h"
#include "../../Engine/Board/Board.h"
#include "../../Enums/PieceType.h"
#include "../../Structs/Move.h"
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <stdint.h>

using bitboard = uint64_t;

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



class MoveGeneratorTest : public ::testing::Test {
protected:
    MoveGenerator mg;
    Board board;

    void SetUp() override {
        // Initialize an empty board
        board.AllPieces = 0;
        for (int i = 0; i < 2; i++) {
            board.AllPiecesOfOneColor[i] = 0;
            for (int j = 0; j < 6; j++) {
                board.PiecePositions[i][j] = 0;
            }
        }
        // Reset castling rights
        board.castlingRights.WhiteShortCastling = false;
        board.castlingRights.WhiteLongCastling = false;
        board.castlingRights.BlackShortCastling = false;
        board.castlingRights.BlackLongCastling = false;
    }

    void AddPiece(int square, PieceType type, bool color) {
        SetBit(board.AllPieces, square);
        SetBit(board.AllPiecesOfOneColor[color], square);
        SetBit(board.PiecePositions[color][static_cast<int>(type)], square);
    }
};

TEST_F(MoveGeneratorTest, PawnMoves) {
    // Test white pawn moves
    AddPiece(8, PieceType::Pawn, true); // White pawn at a2
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::Pawn, silentMoves, captures);
    
    EXPECT_EQ(silentMoves.size(), 2); // Single and double push
    EXPECT_EQ(captures.size(), 0);
}

TEST_F(MoveGeneratorTest, PawnCaptures) {
    // Test white pawn captures
    AddPiece(8, PieceType::Pawn, true); // White pawn at a2
    AddPiece(17, PieceType::Pawn, false); // Black pawn at b3
    
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::Pawn, silentMoves, captures);
    
    EXPECT_EQ(silentMoves.size(), 1); // Only single push (double push blocked)
    EXPECT_EQ(captures.size(), 1); // Capture on b3
}

TEST_F(MoveGeneratorTest, KnightMoves) {
    AddPiece(35, PieceType::Knight, true); // Knight at d4
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::Knight, silentMoves, captures);
    
    EXPECT_EQ(silentMoves.size(), 8); // Knight should have 8 moves from center
}

TEST_F(MoveGeneratorTest, BishopMoves) {
    AddPiece(28, PieceType::Bishop, true); // Bishop at e4
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::Bishop, silentMoves, captures);
    
    EXPECT_GT(silentMoves.size(), 0); // Should have several diagonal moves
}

TEST_F(MoveGeneratorTest, RookMoves) {
    AddPiece(0, PieceType::Rook, true); // Rook at a1
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::Rook, silentMoves, captures);
    
    EXPECT_EQ(silentMoves.size(), 14); // Rook should have 14 moves from corner
}

TEST_F(MoveGeneratorTest, QueenMoves) {
    AddPiece(35, PieceType::Queen, true); // Queen at d4
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::Queen, silentMoves, captures);
    
    EXPECT_GT(silentMoves.size(), 20); // Queen should have many moves from center
}

TEST_F(MoveGeneratorTest, KingMoves) {
    AddPiece(4, PieceType::King, true); // King at e1
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::King, silentMoves, captures);
    
    EXPECT_EQ(silentMoves.size(), 5); // King should have 5 moves from starting position
}

TEST_F(MoveGeneratorTest, CastlingMoves) {
    // Set up position with kings and rooks for castling
    AddPiece(4, PieceType::King, true); // White king
    AddPiece(0, PieceType::Rook, true); // White rook a1
    AddPiece(7, PieceType::Rook, true); // White rook h1
    
    board.castlingRights.WhiteShortCastling = true;
    board.castlingRights.WhiteLongCastling = true;
    
    auto castlingMoves = mg.GenerateCastlingMoves(board, true);
    
    EXPECT_EQ(castlingMoves.size(), 2); // Should have both castling options
}

TEST_F(MoveGeneratorTest, BlockedCastling) {
    AddPiece(4, PieceType::King, true);
    AddPiece(7, PieceType::Rook, true);
    AddPiece(5, PieceType::Bishop, true); // Blocking piece
    
    board.castlingRights.WhiteShortCastling = true;
    
    auto castlingMoves = mg.GenerateCastlingMoves(board, true);
    
    EXPECT_EQ(castlingMoves.size(), 0); // Should have no castling due to block
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}





#endif
