#ifndef INC_3DGRAPHICS_RENDERER_H
# define INC_3DGRAPHICS_RENDERER_H

# include <iostream>
# include <SDL.h>
# include <vector>
# include "Buffer.h"
# include "vectors/vectors.h"


class Renderer {
public:
    Renderer();

    void set_renderer(int width, int height, SDL_Renderer *renderer);

    bool clear();
    void present();

    void render_buffer();

    void draw_rect(int x, int y, int width, int height, uint32_t color);
    void draw_grid(int size = 10, uint32_t color = 0xFF555555);
    void draw(std::vector<Vec2<float>> pos, uint32_t color);
    std::vector<Vec2<float>> project(std::vector<Vec3<float>> vectors);

    inline SDL_Renderer* get() { return _renderer; };

private:
    SDL_Renderer* _renderer;
    Buffer _buffer;
};

#endif //INC_3DGRAPHICS_RENDERER_H
