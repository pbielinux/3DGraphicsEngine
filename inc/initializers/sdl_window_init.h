#ifndef INC_3DGRAPHICS_SDL_WINDOW_INITIALIZER_H
# define INC_3DGRAPHICS_SDL_WINDOW_INITIALIZER_H

# include <SDL.h>
# include "Initializer.h"

class SDLWindowInitializer : public Initializer {
public:
    SDLWindowInitializer(bool fullscreen, bool resizable, int width = 800, int height = 600);

    void setup() override;
    void teardown() override;

    SDL_Window *window() const;
    SDL_Renderer *renderer() const;
    int width() const;
    int height() const;
    bool fullscreen() const;
    bool resizable() const;

private:
    int _width;
    int _height;
    bool _fullscreen;
    bool _resizable;
    SDL_DisplayMode _display;

    SDL_Window *_window;
    SDL_Renderer *_renderer;
};

#endif //INC_3DGRAPHICS_SDL_WINDOW_INITIALIZER_H
