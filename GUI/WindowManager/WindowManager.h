#include <iostream>
#include <SDL2/SDL.h>
#include <string>


#ifndef GUI_WINDOWMANAGER_H
#define GUI_WINDOWMANAGER_H

class WindowManager {

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

        WindowManager() : window(nullptr), renderer(nullptr) {};
        ~WindowManager(){ Destroy(); };

        WindowManager(const WindowManager& other) = delete;
        WindowManager& operator=(const WindowManager& other) = delete;

    public:
        static WindowManager& GetInstance();

        bool TryCreatingWindow(const char* title, int width, int height);

        SDL_Window* GetWindow();
        SDL_Renderer* GetRenderer();

        void Destroy();
};


#endif