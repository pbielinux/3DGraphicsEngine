#include "Buffer.h"

Buffer::Buffer(): _color_buffer(nullptr), _texture(nullptr), _renderer(nullptr) {
}

void Buffer::set_buffer(int width, int height, SDL_Renderer *renderer) {
    win_width = width;
    win_height = height;
    _color_buffer = new uint32_t[win_width * win_height];
    _renderer = renderer;
    _texture = SDL_CreateTexture(renderer,
                                 SDL_PIXELFORMAT_ARGB8888,
                                 SDL_TEXTUREACCESS_STREAMING,
                                 win_width,
                                 win_height);
}

uint32_t Buffer::getPixel(int x, int y) {
    return (_color_buffer[(win_width * y) + x]);
};

void Buffer::set_pixel(int x, int y, uint32_t color) {
    if (x < win_width && y < win_height)
        _color_buffer[(win_width * y) + x] = color;
};

void Buffer::clear_buffer(uint32_t color) {
    for (int y = 0; y < win_height; ++y) {
        for (int x = 0; x < win_width; ++x) {
            set_pixel(x, y, color);
        }
    }
}

SDL_Texture* Buffer::texture() {
    return _texture;
}

SDL_Texture* Buffer::update_texture() {
    SDL_UpdateTexture(_texture,
                      nullptr, _color_buffer,
                      (win_width * sizeof(uint32_t)));
    clear_buffer();
    return _texture;
}