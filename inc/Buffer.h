#ifndef INC_3DGRAPHICS_BUFFER_H
# define INC_3DGRAPHICS_BUFFER_H

# include <SDL.h>
# include "3DGraphics.h"

class Buffer {
public:
    Buffer();

    void set_buffer(int width, int height, SDL_Renderer* renderer);

    inline uint32_t *get() { return(_color_buffer); };

    uint32_t getPixel(int x, int y);

    void set_pixel(int x, int y, uint32_t color);

    void clear_buffer(uint32_t color = 0x00000000);

    SDL_Texture* texture();
    SDL_Texture* update_texture();
    inline int width() { return(win_width);};
    inline int heigth() { return(win_height);};

private:
    uint32_t* _color_buffer;
    SDL_Texture* _texture;
    SDL_Renderer* _renderer;
    int win_width;
    int win_height;
};

#endif //INC_3DGRAPHICS_BUFFER_H
