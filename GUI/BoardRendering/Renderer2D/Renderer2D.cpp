#include "Renderer2D.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../WindowManager/WindowManager.h"

void Renderer2D::RenderFEN(std::string FEN){
    
}


Renderer2D::Renderer2D(){

    WindowManager& WindowManager = WindowManager::GetInstance();
    SDL_Renderer* renderer = WindowManager.GetRenderer();

    for(int piece = 0; piece < 12; piece++){		
		bool isPieceWhite = piece < 6;
		int pieceNameIndex = piece % 6;
		std::string pieceFilePath = (isPieceWhite ?  "WhitePieces/" : "BlackPieces/") + PieceNames[pieceNameIndex] + ".png";
    
        this->PieceTextures[piece] = IMG_LoadTexture(renderer, pieceFilePath.c_str());
    }
}


void Renderer2D::DrawBoard(){

}


void Renderer2D::DrawPiecesFromPosition(BoardPosition position){
    
}
