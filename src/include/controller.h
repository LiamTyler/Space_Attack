#ifndef SRC_INCLUDE_CONTROLLER_H_
#define SRC_INCLUDE_CONTROLLER_H_

#include <SDL2/SDL.h>

class Controller {
    public:
        Controller();
        Controller(int width, int height);
        ~Controller();
        bool Init();
        void Clear();
        void UpdateScreen();
        inline int getWidth() { return screenWidth_; }
        inline int getHeight() { return screenHeight_; }
        inline SDL_Renderer* getRenderer() { return gRenderer_; }
    private:
        int screenWidth_;
        int screenHeight_;
        SDL_Window* gWindow_;
        SDL_Renderer* gRenderer_;
};

#endif
