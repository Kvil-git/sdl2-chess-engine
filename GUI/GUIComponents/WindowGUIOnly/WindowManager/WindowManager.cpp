#include "WindowManager.h"
#include <iostream>
#include <SDL2/SDL.h>


void WindowManager::Destroy(){
    if (renderer != nullptr){
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr){
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

WindowManager& WindowManager::GetInstance(){
    static WindowManager instance;
    return instance;
}

SDL_Window* WindowManager::GetWindow(){
    return window;
}

SDL_Renderer* WindowManager::GetRenderer(){
    return renderer;
}


bool WindowManager::TryCreatingWindow(const char* title, int width, int height){
    if(window != nullptr){
        std::cerr<<"window already exists"<<std::endl;
        return false;
    }

    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return false;
	} 

    // Create window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

