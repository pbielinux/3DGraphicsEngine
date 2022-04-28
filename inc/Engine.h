#ifndef INC_3DGRAPHICS_ENGINE_H
# define INC_3DGRAPHICS_ENGINE_H

# include "3DGraphics.h"
# include "Window.h"

class Engine {
public:
    Engine();
    ~Engine();

    bool isRunning();
    void stop();

    virtual void process_input();
    virtual void update();
    virtual void render();

private:
    std::shared_ptr<Window> m_window;
    std::shared_ptr<SDL_Renderer> m_renderer;
    bool m_isRunning = false;
};

#endif //INC_3DGRAPHICS_ENGINE_H
