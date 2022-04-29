#ifndef INC_3DGRAPHICS_SDL_WINDOW_INITIALIZER_H
# define INC_3DGRAPHICS_SDL_WINDOW_INITIALIZER_H

# include <SDL.h>
# include "Initializer.h"

class SDLWindowInitializer : public Initializer {
public:
    SDLWindowInitializer(int width, int height, bool fullscreen, bool resizable);

    void setup();
    void teardown();

    SDL_Window *window() const;
    SDL_Renderer *renderer() const;

private:
    int width;
    int height;
    bool fullscreen;
    bool resizable;

    SDL_Window *_window;
    SDL_Renderer *_renderer;
};

#endif //INC_3DGRAPHICS_SDL_WINDOW_INITIALIZER_H
