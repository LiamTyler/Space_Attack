#include <iostream>
#include <SDL2/SDL_image.h>
#include "include/controller.h"

using namespace std;

Controller::Controller() : screenWidth_(1280),
    screenHeight_(720),
    gWindow_(nullptr),
    gRenderer_(nullptr),
    timer_(new Timer) {

}

Controller* Controller::getInstance() {
    if (!instance_)
        instance_ = new Controller;
    return instance_;
}

bool Controller::Init(int width, int height) {
    screenWidth_ = width;
    screenHeight_ = height;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
        return false;
    }
    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
        cerr << "Warning: Linear texture filtering not enabled!" << endl;
    }

    ;
    gWindow_ = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                                 SDL_WINDOWPOS_UNDEFINED,
                                                 screenWidth_,
                                                 screenHeight_,
                                                 SDL_WINDOW_SHOWN );
    if( !gWindow_ ) {
        cerr << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
        return false;
    }
    gRenderer_ = SDL_CreateRenderer( gWindow_, -1, SDL_RENDERER_ACCELERATED); // | SDL_RENDERER_PRESENTVSYNC );
    if( !gRenderer_ ) {
        cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
        return false;
    }
    SDL_SetRenderDrawColor( gRenderer_, 0xFF, 0xFF, 0xFF, 0xFF );

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
        cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        return false;
    }

    return true;
}

Controller::~Controller() {
    delete timer_;
    SDL_DestroyRenderer( gRenderer_ );
    SDL_DestroyWindow( gWindow_ );

    IMG_Quit();
    SDL_Quit();
}

// TODO:: Allow for clearing to a different color or background image
void Controller::ClearScreen() {
    timer_->CalculateTimeStep();
    SDL_SetRenderDrawColor( gRenderer_, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer_ );
}

void Controller::UpdateScreen() {
    timer_->Start();
    SDL_RenderPresent( gRenderer_ );
}
