#include <iostream>
#include <SDL2/SDL.h>

#include "3DGraphics.h"
#include "Engine.h"

int main() {
    Engine engine;

    engine.setup();
    while (engine.isRunning()) {
        engine.process_input();
        engine.update();
        engine.render();
    }

    return 0;
}
