#include "initializers/sdl_window_init.h"

SDLWindowInitializer::SDLWindowInitializer(int width, int height, bool fullscreen, bool resizable):
        _width(width), _height(height), _fullscreen(fullscreen), _resizable(resizable),
        _window(nullptr), _renderer(nullptr), _buffer(width, height) {
};

void SDLWindowInitializer::setup() {
    uint32_t flags = 0;

    if (_fullscreen) flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    if (_resizable) flags |= SDL_WINDOW_RESIZABLE;

    if (SDL_CreateWindowAndRenderer(_width, _height, flags, &_window, &_renderer) != 0)
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

Buffer &SDLWindowInitializer::buffer() {
    return _buffer;
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