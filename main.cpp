// g++ main.cpp `pkg-config --cflags --libs sdl2`
#include <iostream>
#include <SDL2/SDL.h>

#include "GUI/GUITypes/WindowGUI/WindowGUI_2D/WindowGUI_2D.h"
#include "GUI/Functions/PositionConverting/PositionConvertingFunctions.h"
#include "GUI/GUIComponents/WindowGUIOnly/WindowManager/WindowManager.h"
#include "GUI/GUIComponents/WindowGUIOnly/InputStorage/InputStorage.h"


bool init();
void kill();



int main(int argc, char** args) {

	if ( !init() ) return 1;
	std::cout<<"init success\n";

	WindowGUI_2D windowGUI;
	
	WindowManager& windowManager = WindowManager::GetInstance();
    InputStorage& inputStorage = InputStorage::GetInstance();
    SDL_Renderer* renderer = windowManager.GetRenderer();


	std::string defaultFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

	
	std::cout<<"default fen: |"<<defaultFEN<<"\n";
	BoardPosition defaultPosition = PositionConverting::FENToBoardPosition(defaultFEN);
	defaultPosition.Output();

	std::cout<<"converted and reconverted back fen: "<< PositionConverting::BoardPositionToFEN(defaultPosition)<<"\n\n";

	SDL_Window* window = windowManager.GetWindow();

	while ( inputStorage.PollEvents()) {
		
		windowGUI.boardRenderer.RenderPosition(defaultPosition);
		SDL_RenderPresent(renderer);
		
	}	

	kill();
	return 0;
}

bool init() {
	WindowManager& WindowManager = WindowManager::GetInstance();
	if(!WindowManager.TryCreatingWindow("testwindow", 400, 400)){
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