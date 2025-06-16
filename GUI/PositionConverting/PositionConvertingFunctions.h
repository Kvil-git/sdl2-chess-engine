#include "../BoardPosition/BoardPosition.h"
#include <string>
#include <stack>
#include "../Move/Move.h"
#include "../Enums/PieceTypes.h"
#include "FENFunctions.h"

#ifndef POSITION_CONVERTING_FUNCTIONS_H
#define POSITION_CONVERTING_FUNCTIONS_H



/*

rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
A FEN record contains six fields, each separated by a space. The fields are as follows:[5]

    Piece placement data: Each rank is described, starting with rank 8 and ending with rank 1, with a "/" between each one; within each rank, the contents of the squares are described in order from the a-file to the h-file. Each piece is identified by a single letter taken from the standard English names in algebraic notation (pawn = "P", knight = "N", bishop = "B", rook = "R", queen = "Q" and king = "K"). White pieces are designated using uppercase letters ("PNBRQK"), while black pieces use lowercase letters ("pnbrqk"). A set of one or more consecutive empty squares within a rank is denoted by a digit from "1" to "8", corresponding to the number of squares.
    Active color: "w" means that White is to move; "b" means that Black is to move.
    Castling availability: If neither side has the ability to castle, this field uses the character "-". Otherwise, this field contains one or more letters: "K" if White can castle kingside, "Q" if White can castle queenside, "k" if Black can castle kingside, and "q" if Black can castle queenside. A situation that temporarily prevents castling does not prevent the use of this notation.
    En passant target square: This is a square over which a pawn has just passed while moving two squares; it is given in algebraic notation. If there is no en passant target square, this field uses the character "-". This is recorded regardless of whether there is a pawn in position to capture en passant.[6] An updated version of the spec has since made it so the target square is recorded only if a legal en passant capture is possible, but the old version of the standard is the one most commonly used.[7][8]
    Halfmove clock: The number of halfmoves since the last capture or pawn advance, used for the fifty-move rule.[9]
    Fullmove number: The number of the full moves. It starts at 1 and is incremented after Black's move.
*/
std::string temp = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";


namespace PositionConverting{

    BoardPosition FENToBoardPosition(std::string FEN) {
        BoardPosition output = BoardPosition();

        for(int i=0; i < 64; i++) {
            char currentChar = FEN[i];
            if(IsCharacterADigit(currentChar)) {
                i += CharacterToDigit(currentChar);
                continue;
            }

            int pieceIdOfCurrentChar = PieceIdByFEN(currentChar);
            if(pieceIdOfCurrentChar == -1) continue;
            
            int row = i/8;
            int column = i%8;
            output.Pieces[row][column] = pieceIdOfCurrentChar;
        }

        return output;
    }

    std::string BoardPositionToFEN(BoardPosition position){
        
        std::string outputFEN;

        for(int row = 0; row < 8; row++){

            int emptyPiecesCounter = 0;

            for(int column = 0; column < 8; column++){
                
                char currentFENchar = FENCharByPieceId(position.Pieces[row][column]);

                if(currentFENchar == 'Z'){
                    emptyPiecesCounter++;
                    continue;
                }

                if(emptyPiecesCounter > 0){
                    outputFEN += DigitToCharacter(emptyPiecesCounter);
                    emptyPiecesCounter = 0;
                }

                outputFEN += currentFENchar;
            }
            
            if(emptyPiecesCounter > 0){
                outputFEN += DigitToCharacter(emptyPiecesCounter);
                emptyPiecesCounter = 0;
            }
            
            outputFEN += '/';

        }
        return outputFEN;
    }


    std::string MoveListToPGN(std::stack<Move> moveList, std::string startingPositionFEN){
        return "";
    }

};




#endif