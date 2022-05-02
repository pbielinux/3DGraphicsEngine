#include "Renderer.h"

Renderer::Renderer(): _renderer(nullptr) {
}

void Renderer::set_renderer(int width, int height, SDL_Renderer *renderer) {
    _renderer = renderer;
    _buffer.set_buffer(width, height, renderer);
}

bool Renderer::clear() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    if (SDL_RenderClear(_renderer)) {
        std::cout << "[ERROR] Renderer: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void Renderer::present() {
    render_buffer();
    SDL_RenderPresent(_renderer);
}

void Renderer::render_buffer() {
    _buffer.update_texture();
    SDL_RenderCopy(_renderer, _buffer.texture(), nullptr, nullptr);
}

void Renderer::draw_rect(int x, int y, int width, int height, uint32_t color) {
    for (int i = 0; i <= height; ++i) {
        for (int j = 0; j <= width; ++j) {
            _buffer.set_pixel(x + j, y + i, color);
        }
    }
};

void Renderer::draw_grid(int size) {
    for (int y = 0; y < _buffer.heigth(); y += size) {
        for (int x = 0; x < _buffer.width(); x += size) {
            _buffer.set_pixel(x, y, 0xFF555555);
        }
    }
};