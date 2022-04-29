#include "Renderer.h"

Renderer::Renderer(): _renderer(nullptr) {
}

void Renderer::set_renderer(SDL_Renderer *renderer) {
    _renderer = renderer;
}

bool Renderer::clear() {
    if (SDL_RenderClear(_renderer)) {
        std::cout << "[ERROR] Renderer: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void Renderer::present() {
    SDL_RenderPresent(_renderer);
}