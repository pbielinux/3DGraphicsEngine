#include "Window.h"

Window::Window():
        m_window(nullptr, SDL_DestroyWindow){
    m_name = "";
    m_x = SDL_WINDOWPOS_CENTERED;
    m_y = SDL_WINDOWPOS_CENTERED;
    m_w = 800;
    m_h = 600;
    m_flags = SDL_WINDOW_BORDERLESS;
};

Window::Window(int w, int h):
        m_window(nullptr, SDL_DestroyWindow), m_w(w), m_h(h) {
    m_name = "";
    m_x = SDL_WINDOWPOS_CENTERED;
    m_y = SDL_WINDOWPOS_CENTERED;
    m_flags = SDL_WINDOW_BORDERLESS;
};

Window::Window(std::string& name, int w, int h):
        m_window(nullptr, SDL_DestroyWindow), m_name(std::move(name)), m_w(w), m_h(h) {
    m_x = SDL_WINDOWPOS_CENTERED;
    m_y = SDL_WINDOWPOS_CENTERED;
    m_flags = SDL_WINDOW_BORDERLESS;
};

Window::Window(std::string& name, int x, int y, int w, int h):
        m_window(nullptr, SDL_DestroyWindow), m_name(std::move(name)), m_x(x), m_y(y), m_w(w), m_h(h) {
    m_flags = SDL_WINDOW_BORDERLESS;
};

Window::Window(std::string& name, int x, int y, int w, int h, Uint32 flags):
        m_window(nullptr, SDL_DestroyWindow), m_name(std::move(name)), m_x(x), m_y(y), m_w(w), m_h(h), m_flags(flags) {
};

bool Window::isCreated() { return(m_created); }

SDL_Window* Window::getAddress() {
    return m_window.get();
}

bool Window::createWindow() {
    if (this->isCreated()) return (false);

    m_window = STL_win_uptr(SDL_CreateWindow(m_name.c_str(), m_x, m_y, m_w, m_h, m_flags),
                                                                         SDL_DestroyWindow);
    if (m_window == nullptr) {
        return (false);
    }
    m_created = true;
    return (true);
}