#include "Engine.h"

using namespace std;

Engine::Engine():
        _sdl_init(make_shared<SDLInitializer>()),
        _sdl_window_init(make_shared<SDLWindowInitializer>(640, 480, false, false)) {
            _startup.add_initializer(_sdl_init);
    _startup.add_initializer(_sdl_window_init);
}

Engine::~Engine() {
    _startup.shutdown();
}

void Engine::init() {
    _startup.init();
    _renderer.set_renderer(_sdl_window_init->renderer());

}

void Engine::process_input() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            std::cout << "[EVENT] Exit" << std::endl;
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                std::cout << "[EVENT] ESCAPE Key pressed" << std::endl;
                isRunning = false;
            }
            break;
    }
}

void Engine::update() {

}

void Engine::render() {
    SDL_SetRenderDrawColor(_renderer.get(), 255, 0, 0, 255);
    SDL_RenderClear(_renderer.get());
    //...
    SDL_RenderPresent(_renderer.get());
}
