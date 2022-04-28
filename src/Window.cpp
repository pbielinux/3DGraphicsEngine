#include "Window.h"

//Window::Window() {
//    _data.name = "";
//    _data.x = SDL_WINDOWPOS_CENTERED;
//    _data.y = SDL_WINDOWPOS_CENTERED;
//    _data.w = WIN_WIDTH;
//    _data.h = WIN_HEIGHT;
//    _data.flags = SDL_WINDOW_BORDERLESS;
//    createWindow();
//    _buffer = std::make_shared<Buffer>(_data.w, _data.h);
//};

Window::Window(std::string name, int x, int y, int w, int h, Uint32 flags):
        _data{ .name = name, .x = x, .y = y, .w = w, .h = h, .flags = flags} {
    createWindow();
    _buffer = std::make_shared<Buffer>(_data.w, _data.h);
};

Window::~Window() {
    SDL_DestroyWindow(_data.address);
}

SDL_Window* Window::getAddress() {
    return (_data.address);
}

void Window::createWindow() {
    _data.address = SDL_CreateWindow(_data.name.c_str(),
                                _data.x, _data.y,
                                _data.w, _data.h,
                                _data.flags);
    if (!_data.address) {
        std::cout << "[ERROR] Creating SDL Window" << std::endl;
    } else
        std::cout << "[INFO] SDL Window created" << std::endl;
}