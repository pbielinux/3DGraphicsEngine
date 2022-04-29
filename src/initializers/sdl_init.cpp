
#include <SDL.h>
#include "initializers/sdl_init.h"

void SDLInitializer::setup() {
    if (SDL_Init(SDL_INIT_EVERYTHING))
        std::cout << "[ERROR] Initialising SDL" << std::endl;
    else
        std::cout << "[INFO] SDL successfully inited" << std::endl;
}

void SDLInitializer::teardown() {
    SDL_Quit();
}