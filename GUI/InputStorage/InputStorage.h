#include <SDL2/SDL.h>
#include <string>
#include <vector>

#include "././Math/VectorN.h"

typedef VectorN<float, 2> Vector2F;

struct InputStorage {
    private:
        InputStorage();
        ~InputStorage(){ Destroy(); };

        InputStorage(const InputStorage& other) = delete;
        InputStorage& operator=(const InputStorage& other) = delete;

    public:
        bool PressedKeys[SDL_NUM_SCANCODES] = {false};
        Vector2F MousePosition;

        static InputStorage& GetInstance(){
            static InputStorage instance;
            return instance;
        }

        bool PollEvents();
        void Destroy();
};