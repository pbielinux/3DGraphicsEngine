#include "initializers/sdl_window_init.h"

SDLWindowInitializer::SDLWindowInitializer(int width, int height, bool fullscreen, bool resizable):
        width(width), height(height), fullscreen(fullscreen), resizable(resizable),
        _window(nullptr), _renderer(nullptr) {
};

void SDLWindowInitializer::setup() {
    uint32_t flags = 0;

    if (fullscreen) flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    if (resizable) flags |= SDL_WINDOW_RESIZABLE;

    if (SDL_CreateWindowAndRenderer(width, height, flags, &_window, &_renderer) != 0)
        std::cout << "[ERROR] Creating SDL Window and Renderer" << std::endl;
}

void SDLWindowInitializer::teardown() {
    if (_renderer)
        SDL_DestroyRenderer(_renderer);
    if (_window)
        SDL_DestroyWindow(_window);
}

SDL_Window *SDLWindowInitializer::window() const {
    return _window;
}

SDL_Renderer *SDLWindowInitializer::renderer() const {
    return _renderer;
}