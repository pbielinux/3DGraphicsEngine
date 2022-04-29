#ifndef INC_3DGRAPHICS_RENDERER_H
# define INC_3DGRAPHICS_RENDERER_H

# include <iostream>
# include <SDL.h>
# include "Buffer.h"


class Renderer {
public:
    Renderer();

    void set_renderer(SDL_Renderer *renderer);

    void render_color_buffer(Buffer& color_buffer, SDL_Texture* texture);

    bool clear();
    void present();

    inline SDL_Renderer* get() { return _renderer; };

private:
    SDL_Renderer* _renderer;
};

#endif //INC_3DGRAPHICS_RENDERER_H
