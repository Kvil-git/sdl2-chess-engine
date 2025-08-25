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
    
    EXPECT_EQ(silentMoves.size(), 2); // Single and double push (double push not blocked)
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


// Add these tests to MoveGeneratorTests.cpp

TEST_F(MoveGeneratorTest, PawnPromotion) {
    // Test white pawn promotion
    AddPiece(48, PieceType::Pawn, true); // White pawn at a7
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::Pawn, silentMoves, captures);
    
    // Should have promotion moves (single push and double push)
    EXPECT_GT(silentMoves.size(), 0);
}

TEST_F(MoveGeneratorTest, EnPassantCapture) {
    // Test en passant capture
    AddPiece(27, PieceType::Pawn, true); // White pawn at d5
    AddPiece(28, PieceType::Pawn, false); // Black pawn at e5
    
    // Set en passant square
    board.enPassantSquare = 36; // e6
    
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::Pawn, silentMoves, captures);
    
    // Should have en passant capture option
    bool hasEnPassant = false;
    for (const auto& capture : captures) {
        if (capture.toSquare == 36) { // e6
            hasEnPassant = true;
            break;
        }
    }
    EXPECT_TRUE(hasEnPassant);
}

TEST_F(MoveGeneratorTest, KingInCheck) {
    // Test that king moves avoid check
    AddPiece(4, PieceType::King, true); // White king at e1
    AddPiece(28, PieceType::Rook, false); // Black rook at e5
    
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::King, silentMoves, captures);
    
    // King should have limited moves to avoid check
    EXPECT_LT(silentMoves.size(), 8);
}

TEST_F(MoveGeneratorTest, PinnedPiece) {
    // Test that pinned pieces can't move
    AddPiece(4, PieceType::King, true); // White king at e1
    AddPiece(12, PieceType::Bishop, true); // White bishop at e2
    AddPiece(28, PieceType::Bishop, false); // Black bishop at e5
    
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::Bishop, silentMoves, captures);
    
    // Bishop should be pinned and have no legal moves
    EXPECT_EQ(silentMoves.size() + captures.size(), 0);
}

TEST_F(MoveGeneratorTest, ComplexPosition) {
    // Test a complex position with multiple pieces
    // Set up a typical opening position
    AddPiece(0, PieceType::Rook, true); // White rook at a1
    AddPiece(1, PieceType::Knight, true); // White knight at b1
    AddPiece(2, PieceType::Bishop, true); // White bishop at c1
    AddPiece(3, PieceType::Queen, true); // White queen at d1
    AddPiece(4, PieceType::King, true); // White king at e1
    AddPiece(5, PieceType::Bishop, true); // White bishop at f1
    AddPiece(6, PieceType::Knight, true); // White knight at g1
    AddPiece(7, PieceType::Rook, true); // White rook at h1
    
    // Add some pawns
    for (int i = 8; i < 16; i++) {
        AddPiece(i, PieceType::Pawn, true);
    }
    
    // Test all piece types
    std::vector<std::pair<PieceType, int>> expectedMoves = {
        {PieceType::Pawn, 16},    // 16 possible pawn moves (each can move 2 squares)
        {PieceType::Knight, 4},   // 4 knight moves (2 for each knight)
        {PieceType::Bishop, 0},   // 0 bishop moves (blocked by pawns)
        {PieceType::Rook, 0},     // 0 rook moves (blocked by pawns)
        {PieceType::Queen, 0},    // 0 queen moves (blocked by pawns)
        {PieceType::King, 0}      // 0 king moves (blocked by pawns)
    };
    
    for (const auto& [pieceType, expected] : expectedMoves) {
        std::vector<Move> silentMoves;
        std::vector<Move> captures;
        
        mg.FillPieceMoveArrays(board, true, pieceType, silentMoves, captures);
        
        EXPECT_EQ(silentMoves.size() + captures.size(), expected)
            << "Piece type: " << static_cast<int>(pieceType);
    }
}

TEST_F(MoveGeneratorTest, EdgeOfBoard) {
    // Test pieces on the edge of the board
    AddPiece(0, PieceType::Rook, true); // White rook at a1
    AddPiece(7, PieceType::Rook, true); // White rook at h1
    AddPiece(56, PieceType::Rook, true); // White rook at a8
    AddPiece(63, PieceType::Rook, true); // White rook at h8
    
    std::vector<Move> silentMoves;
    std::vector<Move> captures;
    
    mg.FillPieceMoveArrays(board, true, PieceType::Rook, silentMoves, captures);
    
    // Each rook should have 14 moves from corner (7 horizontal + 7 vertical)
    EXPECT_EQ(silentMoves.size() + captures.size(), 56); // 4 rooks * 14 moves
}

TEST_F(MoveGeneratorTest, CastlingWhenInCheck) {
    // Test that castling is not allowed when in check
    AddPiece(4, PieceType::King, true); // White king at e1
    AddPiece(7, PieceType::Rook, true); // White rook at h1
    AddPiece(28, PieceType::Queen, false); // Black queen at e5 (checking)
    
    board.castlingRights.WhiteShortCastling = true;
    
    auto castlingMoves = mg.GenerateCastlingMoves(board, true);
    
    // Should not be able to castle while in check
    EXPECT_EQ(castlingMoves.size(), 0);
}

TEST_F(MoveGeneratorTest, CastlingThroughCheck) {
    // Test that castling is not allowed through attacked squares
    AddPiece(4, PieceType::King, true); // White king at e1
    AddPiece(7, PieceType::Rook, true); // White rook at h1
    AddPiece(30, PieceType::Rook, false); // Black rook at g5 (attacking f1)
    
    board.castlingRights.WhiteShortCastling = true;
    
    auto castlingMoves = mg.GenerateCastlingMoves(board, true);
    
    // Should not be able to castle through check
    EXPECT_EQ(castlingMoves.size(), 0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}





#endif
