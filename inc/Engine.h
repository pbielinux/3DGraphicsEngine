#ifndef INC_3DGRAPHICS_APP_H
# define INC_3DGRAPHICS_APP_H

# include "Window.h"

class Engine {
public:
    Engine() {};
    ~Engine() {};

    bool isRunning();
    bool setup();
    void stop();

    void process_input();
    void update();
    void render();

private:
    Window m_window;
    SDL_Renderer *m_renderer;
    bool m_isRunning = false;
};

#endif //INC_3DGRAPHICS_APP_H
