#include "Engine.h"

bool Engine::isRunning() { return (m_isRunning); };

bool Engine::setup() {
    // Init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "[ERROR] Initialising SDL" << std::endl;
        return (false);
    };
    std::cout << "[INFO] STL successfully inited" << std::endl;

    // Init Window
    m_window = new Window();
    if (!m_window->createWindow()) {
        std::cout << "[ERROR] Initialising Window" << std::endl;
        return (false);
    }
    std::cout << "[INFO] STL Window created" << std::endl;

    // Init Renderer
    m_renderer = SDL_CreateRenderer(m_window->getAddress(), -1, 0);
    if (!m_renderer) {
        std::cout << "[ERROR] Creating STL renderer" << std::endl;
        return (false);
    }
    std::cout << "[INFO] Renderer successfully created" << std::endl;
    m_isRunning = true;
    return (true);
}

void Engine::stop() { m_isRunning = false; };

void Engine::process_input() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            this->stop();
            std::cout << "[EVENT] Exit" << std::endl;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                std::cout << "[EVENT] ESCAPE Key pressed" << std::endl;
                this->stop();
            }
            break;
        default:
            break;
    }
}

void Engine::update() {

}

void Engine::render() {
    SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    //...
    SDL_RenderPresent(m_renderer);
}
