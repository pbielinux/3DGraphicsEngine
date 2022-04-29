#ifndef INC_3DGRAPHICS_SDL_WINDOW_INITIALIZER_H
# define INC_3DGRAPHICS_SDL_WINDOW_INITIALIZER_H

# include <SDL.h>
# include "Initializer.h"
# include "Buffer.h"

class SDLWindowInitializer : public Initializer {
public:
    SDLWindowInitializer(int width, int height, bool fullscreen, bool resizable);

    void setup() override;
    void teardown() override;

    SDL_Window *window() const;
    SDL_Renderer *renderer() const;
    Buffer &buffer();
    int width() const;
    int height() const;
    bool fullscreen() const;
    bool resizable() const;

private:
    int _width;
    int _height;
    bool _fullscreen;
    bool _resizable;

    SDL_Window *_window;
    SDL_Renderer *_renderer;
    Buffer _buffer;
};

#endif //INC_3DGRAPHICS_SDL_WINDOW_INITIALIZER_H
