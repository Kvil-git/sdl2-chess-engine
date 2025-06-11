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
	
	if ( !init() ) return 1;

	while ( inputStorage.PollEvents()) {
		// wait before processing the next frame
		for(int i=0; i<512; i++){
			std::cout << inputStorage.PressedKeys[i] <<" "<<std::endl;
		}
		SDL_Delay(10); 
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
	WindowManager::GetInstance().Destroy();
	InputStorage::GetInstance().Destroy();

	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
}