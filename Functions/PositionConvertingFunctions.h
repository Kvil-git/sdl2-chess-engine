#include <string>
#include <stack>
#include <vector>
#include "../Structs/BoardArray.h"
#include "../Structs/Move.h"
#include "../Enums/PieceTypes.h"
#include "FENFunctions.h"

#include "StringFunctions.cpp"


#ifndef POSITION_CONVERTING_FUNCTIONS_H
#define POSITION_CONVERTING_FUNCTIONS_H


namespace PositionConverting{

    BoardArray FENToBoardArray(std::string FEN) {
        BoardArray output = BoardArray();

        std::vector<std::string> rows = StringFunctions::SplitStringIntoWordsByDelimiter(FEN, "/");

        for(int row = 0; row < rows.size(); row++){
            for(int column = 0; column < rows[row].length(); column++){
                char currentChar = rows[row][column];
                if(currentChar == ' ') break;
                
                if(IsCharacterADigit(currentChar)) {
                    column += CharacterToDigit(currentChar);
                    continue;
                }

                int pieceIdOfCurrentChar = PieceIdByFEN(currentChar);
                if(pieceIdOfCurrentChar == PieceTypes::NONE){
                    continue;
                }

                output.Pieces[row][column] = pieceIdOfCurrentChar;
            }
        }

        return output;
    }

    std::string BoardArrayToFEN(BoardArray position){
        
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
            
            if(row < 7) outputFEN += '/';

        }
        return outputFEN;
    }


    std::string MoveListToPGN(std::stack<Move> moveList, std::string startingPositionFEN){
        return "";
    }

};




#endif