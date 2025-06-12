#include <SDL2/SDL.h>
#include <string>
#include <vector>

#include "../../Math/Vector.h"

struct InputStorage {
    private:
        InputStorage(){};
        ~InputStorage(){ Destroy(); };

        InputStorage(const InputStorage& other) = delete;
        InputStorage& operator=(const InputStorage& other) = delete;

    public:
        bool PressedKeys[SDL_NUM_SCANCODES] = {false};
        Vector<int, 2> MousePosition, MousePositionChange;

        static InputStorage& GetInstance(){
            static InputStorage instance;
            return instance;
        };

        bool PollEvents();
        void Destroy();
};