// g++ main.cpp `pkg-config --cflags --libs sdl2`
#include <iostream>
#include <SDL2/SDL.h>
#include "GUI/WindowManager/WindowManager.cpp"
#include "GUI/InputStorage/InputStorage.cpp"
#include "Game/Game.h"


bool init();
void kill();


int main(int argc, char** args) {
	InputStorage& inputStorage = InputStorage::GetInstance();
	std::cout<<"test\n";

	Game newGame = Game();
	
	if ( !init() ) return 1;

	while ( inputStorage.PollEvents()) {
		//main loop
		while (not newGame.IsGameOver()) {
			newGame.AskCurrentPlayerToMove();
		}
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