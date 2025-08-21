#include "Renderer_2D.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../WindowGUIOnly/WindowManager/WindowManager.h"
#include "../../../../Enums/PieceType.h"


Renderer2D::Renderer2D(int squareSize){

    this->squareSize = squareSize;

    IMG_Init(IMG_INIT_PNG);

    WindowManager& WindowManager = WindowManager::GetInstance();
    SDL_Renderer* renderer = WindowManager.GetRenderer();


    std::string PieceNames[6] = {
        "pawn", "knight", "bishop", "rook", "queen", "king"
    };


    for(int piece = 0; piece < 12; piece++){		
		bool isPieceWhite = piece < 6;
		int pieceNameIndex = piece % 6;
		std::string pieceFilePath = (isPieceWhite ?  "Assets/WhitePieces/" : "Assets/BlackPieces/") + PieceNames[pieceNameIndex] + ".png";
    
        this->PieceTextures[piece] = IMG_LoadTexture(renderer, pieceFilePath.c_str());

        // Make sure format succeeded
		if ( !PieceTextures[piece] ) {
			std::cerr << "Error loading image texture: " << IMG_GetError() << std::endl;
		}
    }
}


Renderer2D::~Renderer2D(){
    return;
}





void Renderer2D::DrawBoard(bool fromWhitePerspective){
    WindowManager& windowManager = WindowManager::GetInstance();
    SDL_Renderer* renderer = windowManager.GetRenderer();

    for(int row=0; row < 8; row++) {
        bool rowStartsWithWhiteSquare = (row % 2 == 1);
        for(int column=0; column < 8; column++) {
            bool isColorWhite = column % 2; //if row starts with white color then we check for even column
            if(rowStartsWithWhiteSquare == false) isColorWhite = !isColorWhite; //if row starts with black color we invert our calculation

            if(isColorWhite){
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 255, 100, 0);
            }

            SDL_Rect boardSquare;
            boardSquare.x = column * this->squareSize;
            boardSquare.y = row * this->squareSize;
            boardSquare.w = this->squareSize;
            boardSquare.h = this->squareSize;

            SDL_RenderFillRect(renderer, &boardSquare);
        }
    }
    return;
}


void Renderer2D::DrawPieceAt(int piece, SDL_Rect destination){
    WindowManager& windowManager = WindowManager::GetInstance();
    SDL_Renderer* renderer = windowManager.GetRenderer();

    SDL_RenderCopy(renderer, this->PieceTextures[piece], NULL, &destination);
    return;
}


void Renderer2D::DrawPiecesFromPositionFromWhitePerspective(BoardArray position){
    for(int row=0; row<8; row++) {
        for(int column=0; column<8; column++) {

            int currentPiece = position.Pieces[row][column];
            if(currentPiece == ChessPiece::NONE) continue;

            SDL_Rect currentPieceDestination;
            currentPieceDestination.x = squareSize * column;
            currentPieceDestination.y = squareSize * row;
            currentPieceDestination.w = squareSize;
            currentPieceDestination.h = squareSize;
            
            DrawPieceAt(position.Pieces[row][column], currentPieceDestination);
        }
    }
}

void Renderer2D::DrawPiecesFromPositionFromBlackPerspective(BoardArray position){
        for(int row=0; row<8; row++) {
        for(int column=0; column<8; column++) {

            int currentPiece = position.Pieces[row][column];
            if(currentPiece == ChessPiece::NONE) continue;

            SDL_Rect currentPieceDestination;
            currentPieceDestination.x = squareSize * column;
            currentPieceDestination.y = squareSize * row;
            currentPieceDestination.w = squareSize;
            currentPieceDestination.h = squareSize;
            
            DrawPieceAt(position.Pieces[row][column], currentPieceDestination);
        }
    }
}

void Renderer2D::DrawPiecesFromPosition(BoardArray position, bool fromWhitePerspective){
    if(fromWhitePerspective){
        DrawPiecesFromPositionFromWhitePerspective(position);
        return;
    }

    DrawPiecesFromPositionFromBlackPerspective(position);
    return;
}




void Renderer2D::RenderPosition(BoardArray position, bool fromWhitePerspective){
    this->DrawBoard(fromWhitePerspective);
    this->DrawPiecesFromPosition(position, fromWhitePerspective);
    return;
}