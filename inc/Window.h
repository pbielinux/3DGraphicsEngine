#ifndef INC_3DGRAPHICS_WINDOW_H
# define INC_3DGRAPHICS_WINDOW_H

# include <iostream>
# include <memory>
# include <optional>
# include <functional>
# include <SDL2/SDL.h>

class Window {
    using STL_win_uptr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;

public:
    Window();
    Window(int w, int h);
    Window(std::string& name, int w, int h);
    Window(std::string& name, int x, int y, int w, int h);
    Window(std::string& name, int x, int y, int w, int h, Uint32 flags);

    SDL_Window *getAddress();

    bool createWindow();

    bool isCreated();
private:
    STL_win_uptr m_window;
    std::string m_name;
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    Uint32 m_flags;
    bool m_created = false;
};

#endif //INC_3DGRAPHICS_WINDOW_H
