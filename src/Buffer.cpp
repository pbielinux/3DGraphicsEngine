#include "Buffer.h"

Buffer::Buffer(int window_width, int window_height):
        win_width(window_width), win_height(window_height) {
    _color_buffer = new uint32_t[window_width * window_height];
}

uint32_t Buffer::getPixel(int x, int y) {
    return (_color_buffer[(win_width * y) * x]);
};

void Buffer::setPixel(int x, int y, uint32_t color) {
    _color_buffer[(win_width * y) * x] = color;
};

void Buffer::clearBuffer(uint32_t color) {
    for (int y = 0; y < win_height; ++y) {
        for (int x = 0; x < win_width; ++x) {
            setPixel(x, y, color);
        }
    }
}