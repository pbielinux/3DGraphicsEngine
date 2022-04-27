#ifndef INC_3DGRAPHICS_BUFFER_H
# define INC_3DGRAPHICS_BUFFER_H

# include "3DGraphics.h"

class Buffer {
public:
    Buffer() {};
private:
    std::array<uint32_t, WIN_WIDTH * WIN_HEIGHT> color_buffer;
};

#endif //INC_3DGRAPHICS_BUFFER_H
