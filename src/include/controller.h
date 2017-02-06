#ifndef SRC_INCLUDE_CONTROLLER_H_
#define SRC_INCLUDE_CONTROLLER_H_

#include <SDL2/SDL.h>

class Controller {
    public:
        Controller();
        Controller(int width, int height);
        ~Controller();
        bool Init();
        void ClearScreen();
        void UpdateScreen();
        int getWidth() { return screenWidth_; }
        int getHeight() { return screenHeight_; }
        SDL_Renderer* getRenderer() { return gRenderer_; }
    private:
        int screenWidth_;
        int screenHeight_;
        SDL_Window* gWindow_;
        SDL_Renderer* gRenderer_;
};

#endif
