#ifndef INC_3DGRAPHICS_WINDOW_H
# define INC_3DGRAPHICS_WINDOW_H

# include "3DGraphics.h"
# include "Buffer.h"

struct Win_data {
    SDL_Window* address;
    std::string name;
    int x;
    int y;
    int w;
    int h;
    Uint32 flags;
};

class Window {
public:
    Window( std::string name = "",
            int x = SDL_WINDOWPOS_CENTERED,
            int y = SDL_WINDOWPOS_CENTERED,
            int w = 800,
            int h = 600,
            Uint32 flags = SDL_WINDOW_BORDERLESS);
    ~Window();

    SDL_Window *getAddress();

    void createWindow();

private:
    Win_data _data;
    std::shared_ptr<Buffer> _buffer;
};

#endif //INC_3DGRAPHICS_WINDOW_H
