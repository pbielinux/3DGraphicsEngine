#ifndef INC_3DGRAPHICS_RENDERER_H
# define INC_3DGRAPHICS_RENDERER_H

# include <iostream>
# include <SDL.h>
# include "Buffer.h"


class Renderer {
public:
    Renderer();

    void set_renderer(int width, int height, SDL_Renderer *renderer);

    bool clear();
    void present();

    void render_buffer();

    void draw_rect(int x, int y, int width, int height, uint32_t color);
    void draw_grid(int size = 10);

    inline SDL_Renderer* get() { return _renderer; };

private:
    SDL_Renderer* _renderer;
    Buffer _buffer;
};

#endif //INC_3DGRAPHICS_RENDERER_H
