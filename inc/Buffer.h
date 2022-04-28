#ifndef INC_3DGRAPHICS_BUFFER_H
# define INC_3DGRAPHICS_BUFFER_H

# include "3DGraphics.h"

class Buffer {
public:
    Buffer(int window_width, int window_height);

    uint32_t getPixel(int x, int y);

    void setPixel(int x, int y, uint32_t color);

    void clearBuffer(uint32_t color = 0x00000000);

private:
    uint32_t* p_color_buffer;
    int win_width;
    int win_height;
};

#endif //INC_3DGRAPHICS_BUFFER_H
