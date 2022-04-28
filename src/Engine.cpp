#include "Engine.h"

Engine::Engine() {
    // Init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "[ERROR] Initialising SDL" << std::endl;
    } else
        std::cout << "[INFO] SDL successfully inited" << std::endl;

    // Init Window
    m_window = std::make_shared<Window>();

    // Init Renderer
    m_renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(m_window->getAddress(), -1, 0),
                                                SDL_DestroyRenderer);
    if (!m_renderer.get()) {
        std::cout << "[ERROR] Creating SDL renderer" << std::endl;
    } else
        std::cout << "[INFO] Renderer successfully created" << std::endl;


    m_isRunning = true;
}

Engine::~Engine() {
    SDL_Quit();
}

bool Engine::isRunning() { return (m_isRunning); }

void Engine::stop() { m_isRunning = false; }

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
    SDL_SetRenderDrawColor(m_renderer.get(), 255, 0, 0, 255);
    SDL_RenderClear(m_renderer.get());
    //...
    SDL_RenderPresent(m_renderer.get());
}
