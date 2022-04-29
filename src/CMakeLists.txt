# Project setup ------------------------------------------------------------------------------------
project(Graphs)

# Dependencies -------------------------------------------------------------------------------------
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Build --------------------------------------------------------------------------------------------
include_directories(../inc)

# Sources & Paths ----------------------------------------------------------------------------------
add_executable(${PROJECT_NAME}
        main.cpp
        Engine.cpp
        Buffer.cpp
        Renderer.cpp
        Initializer.cpp
        initializers/sdl_init.cpp
        initializers/sdl_window_init.cpp
        )
target_link_libraries(Graphs ${SDL2_LIBRARIES})
