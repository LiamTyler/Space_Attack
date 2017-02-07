#ifndef SRC_INCLUDE_CONTROLLER_H_
#define SRC_INCLUDE_CONTROLLER_H_

#include <SDL2/SDL.h>

class Controller {
    public:
        ~Controller();

        bool Init(int width, int height);
        void ClearScreen();
        void UpdateScreen();

        static Controller* getInstance();
        int getWidth() { return screenWidth_; }
        int getHeight() { return screenHeight_; }
        SDL_Renderer* getRenderer() { return gRenderer_; }
    private:
        Controller();

        static Controller* instance_;
        int screenWidth_;
        int screenHeight_;
        SDL_Window* gWindow_;
        SDL_Renderer* gRenderer_;
};

#endif
