// g++ main.cpp `pkg-config --cflags --libs sdl2`
#include <iostream>
#include <SDL2/SDL.h>
#include "GUI/WindowManager/WindowManager.cpp"
#include "GUI/InputStorage/InputStorage.cpp"

bool init();
void kill();
bool loop();

// Pointers to our window and renderer
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* winSurface;

int main(int argc, char** args) {

	InputStorage& inputStorage = InputStorage::GetInstance();
	std::cout<<"test\n";
	if ( !init() ) return 1;

	while ( inputStorage.PollEvents()) {
		
	}

	kill();
	return 0;
}

bool loop() {
	// Clear the window to white
	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
	SDL_RenderClear( renderer );
	// Update window
	SDL_RenderPresent( renderer );

	return true;
}

bool init() {
	WindowManager& WindowManager = WindowManager::GetInstance();
	if(!WindowManager.TryCreatingWindow("testwindow", 600, 400)){
		return false;
	}
	window = WindowManager.GetWindow();
	renderer = WindowManager.GetRenderer();

	winSurface = SDL_GetWindowSurface( window );
	if ( !winSurface ) {
		std::cout << "Error getting surface: " << SDL_GetError() << std::endl;
		system("pause");
		return false;
	}

	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
	SDL_RenderClear( renderer );
	return true;
}

void kill() {
	// Quit
	InputStorage::GetInstance().Destroy();
	WindowManager::GetInstance().Destroy();
}