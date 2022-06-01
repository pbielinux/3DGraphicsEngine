#include "Engine.h"
#include "forms/cube.h"

using namespace std;

Cube cube;

Engine::Engine():
        _sdl_init(make_shared<SDLInitializer>()),
        _sdl_window_init(make_shared<SDLWindowInitializer>(false, false, 1280, 720)) {
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

    for (float x = -1; x <= 1; x += 0.25) {
        for (float y = -1; y <= 1; y += 0.25) {
            for (float z = -1; z <= 1; z += 0.25) {
                Vec3<float> new_point(x, y, z);
                cube.add(new_point);
            }
        }
    }
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
//            if (event.key.keysym.sym == SDLK_w)
//                sqr.y -= 10;
//            if (event.key.keysym.sym == SDLK_s)
//                sqr.y += 10;
//            if (event.key.keysym.sym == SDLK_a)
//                sqr.x -= 10;
//            if (event.key.keysym.sym == SDLK_d)
//                sqr.x += 10;
            break;
    }
}

void Engine::update() {

}

void Engine::render() {
    _renderer.clear();
    _renderer.draw_grid(10);

    auto projection = _renderer.project(cube.get());

    for (auto point : projection) {
        _renderer.draw_rect(
                point.x + _sdl_window_init->width() / 2,
                point.y + _sdl_window_init->height() / 2,
                4,
                4,
                0xFFFFFF00);
    }
    _renderer.present();
}
