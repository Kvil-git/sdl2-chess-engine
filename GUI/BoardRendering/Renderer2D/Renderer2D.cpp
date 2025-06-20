#include "Renderer2D.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../WindowManager/WindowManager.h"


Renderer2D::Renderer2D(int squareSize){

    this->squareSize = squareSize;

    WindowManager& WindowManager = WindowManager::GetInstance();
    SDL_Renderer* renderer = WindowManager.GetRenderer();

    for(int piece = 0; piece < 12; piece++){		
		bool isPieceWhite = piece < 6;
		int pieceNameIndex = piece % 6;
		std::string pieceFilePath = (isPieceWhite ?  "WhitePieces/" : "BlackPieces/") + PieceNames[pieceNameIndex] + ".png";
    
        this->PieceTextures[piece] = IMG_LoadTexture(renderer, pieceFilePath.c_str());
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




void DrawPiecesFromPositionFromWhitePerspective(BoardPosition position){
     
}

void DrawPiecesFromPositionFromBlackPerspective(BoardPosition position){
    
}

void Renderer2D::DrawPiecesFromPosition(BoardPosition position, bool fromWhitePerspective){
    if(fromWhitePerspective){
        DrawPiecesFromPositionFromWhitePerspective(position);
    } else {
        DrawPiecesFromPositionFromBlackPerspective(position);
    }
    return;
}




void Renderer2D::RenderPosition(BoardPosition position, bool fromWhitePerspective){
    this->DrawBoard(fromWhitePerspective);
    this->DrawPiecesFromPosition(position, fromWhitePerspective);
    return;
}