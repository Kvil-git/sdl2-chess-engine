// g++ main.cpp `pkg-config --cflags --libs sdl2`
#include <iostream>
#include <SDL2/SDL.h>


#include "GUI/Enums/PlayerColors.h"
#include "GUI/Enums/PieceTypes.h"

#include "GUI/WindowManager/WindowManager.cpp"
#include "GUI/InputStorage/InputStorage.cpp"
#include "GUI/Game/Game.cpp"
#include "GUI/BoardRendering/Renderer2D/Renderer2D.cpp"
#include "GUI/PositionConverting/PositionConvertingFunctions.h"

bool init();
void kill();


int main(int argc, char** args) {
	InputStorage& inputStorage = InputStorage::GetInstance();
	std::cout<<"test\n";

	PlayerColors playerColor = PlayerColors::White;
	Game newGame = Game(playerColor);
	

	Renderer2D boardRenderer = Renderer2D();
    SDL_Renderer* renderer = WindowManager::GetInstance().GetRenderer();


	std::string defaultFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";


	
	std::cout<<"default fen: |"<<defaultFEN<<"\n";

	BoardPosition defaultPosition = PositionConverting::FENToBoardPosition(defaultFEN);
	defaultPosition.Output();

	std::cout<<"converted and reconverted back fen: |"<< PositionConverting::BoardPositionToFEN(defaultPosition)<<"\n\n";



	if ( !init() ) return 1;
	std::cout<<"init success\n";

	

	while ( inputStorage.PollEvents()) {
		
		while (not newGame.IsGameOver()) {
			newGame.AskCurrentPlayerToMove();
			newGame.GetCurrentFEN();
		}

		boardRenderer.RenderPosition(defaultPosition);
		SDL_RenderPresent(renderer);
		
	}

	kill();
	return 0;
}

bool init() {
	WindowManager& WindowManager = WindowManager::GetInstance();
	if(!WindowManager.TryCreatingWindow("testwindow", 600, 400)){
		return false;
	}
	SDL_Window* window = WindowManager.GetWindow();
	SDL_Renderer* renderer = WindowManager.GetRenderer();

	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
	SDL_RenderClear( renderer );
	return true;
}

void kill() {
	// Quit
	InputStorage::GetInstance().Destroy();
	WindowManager::GetInstance().Destroy();
}