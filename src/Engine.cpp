#include "Engine.h"

using namespace std;

struct Rect {
    int width;
    int height;
    int x;
    int y;
    uint32_t color;
};

Rect sqr = {.width = 100, .height = 100, .x = 200, .y = 200, .color = 0xff00ff00};

Engine::Engine():
        _sdl_init(make_shared<SDLInitializer>()),
        _sdl_window_init(make_shared<SDLWindowInitializer>(true, false)) {
    _startup.add_initializer(_sdl_init);
    _startup.add_initializer(_sdl_window_init);
}

Engine::~Engine() {
    _startup.shutdown();
}

void Engine::init() {
    _startup.init();
    _renderer.set_renderer(_sdl_window_init->width(),
                           _sdl_window_init->height(),
                           _sdl_window_init->renderer());
    isRunning = true;
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
            if (event.key.keysym.sym == SDLK_w)
                sqr.y -= 10;
            if (event.key.keysym.sym == SDLK_s)
                sqr.y += 10;
            if (event.key.keysym.sym == SDLK_a)
                sqr.x -= 10;
            if (event.key.keysym.sym == SDLK_d)
                sqr.x += 10;
            break;
    }
}

void Engine::update() {

}

void Engine::render() {
    _renderer.clear();
    _renderer.draw_grid(10);
    _renderer.draw_rect(sqr.x, sqr.y, sqr.width, sqr.height, sqr.color);
    _renderer.present();
}
