#include "initializers/sdl_window_init.h"

SDLWindowInitializer::SDLWindowInitializer(bool fullscreen, bool resizable, int width, int height) :
        _width(width), _height(height), _fullscreen(fullscreen), _resizable(resizable),
        _window(nullptr), _renderer(nullptr) {
};

void SDLWindowInitializer::setup() {
    uint32_t flags = 0;

    SDL_GetCurrentDisplayMode(0, &_display);
    if (_fullscreen) {
        _width = _display.w;
        _height = _display.h;
        flags |= SDL_WINDOW_FULLSCREEN;
    }
    if (_resizable) flags |= SDL_WINDOW_RESIZABLE;
    if(!(_window = SDL_CreateWindow("",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               _width, _height, flags)))
        std::cout << "[ERROR] Creating SDL Window" << std::endl;
    if (!(_renderer = SDL_CreateRenderer(_window, -1, flags)))
        std::cout << "[ERROR] Creating SDL Renderer" << std::endl;
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

int SDLWindowInitializer::width() const {
    return _width;
}

int SDLWindowInitializer::height() const {
    return _height;
}

bool SDLWindowInitializer::fullscreen() const {
    return _fullscreen;
}

bool SDLWindowInitializer::resizable() const {
    return _resizable;
}