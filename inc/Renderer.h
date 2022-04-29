#ifndef INC_3DGRAPHICS_RENDERER_H
# define INC_3DGRAPHICS_RENDERER_H

# include <iostream>
# include <SDL.h>

class Renderer {
public:
    void set_renderer(SDL_Renderer *renderer);

    bool clear();
    void present();

    inline SDL_Renderer* get() { return _renderer; };

private:
    SDL_Renderer* _renderer;
};

#endif //INC_3DGRAPHICS_RENDERER_H
