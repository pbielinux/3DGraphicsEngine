#ifndef INC_3DGRAPHICS_SDL_INITIALIZER_H
# define INC_3DGRAPHICS_SDL_INITIALIZER_H

# include "Initializer.h"

class SDLInitializer : public Initializer {
public:
    void setup();
    void teardown();
};

#endif //INC_3DGRAPHICS_SDL_INITIALIZER_H
