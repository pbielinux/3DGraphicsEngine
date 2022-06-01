#ifndef INC_3DGRAPHICS_ENGINE_H
# define INC_3DGRAPHICS_ENGINE_H

# include <memory>
# include "Initializer.h"
# include "initializers/sdl_init.h"
# include "initializers/sdl_window_init.h"
# include "Renderer.h"
# include "Buffer.h"
# include "vectors/vectors.h"

class Engine {
public:
    Engine();
    ~Engine();

    void init();

    void process_input();
    void update();
    void render();

    bool isRunning;
private:
    Startup _startup;
    std::shared_ptr<SDLInitializer> _sdl_init;
    std::shared_ptr<SDLWindowInitializer> _sdl_window_init;

    Renderer _renderer;
};

#endif //INC_3DGRAPHICS_ENGINE_H
