# Project setup ------------------------------------------------------------------------------------
project(ut-main)
enable_testing()

# Sources & Paths ----------------------------------------------------------------------------------
add_executable(${PROJECT_NAME}
        ut_main.cpp
        )

# Tests --------------------------------------------------------------------------------------------
add_test(${PROJECT_NAME} ${PROJECT_NAME})

# Build --------------------------------------------------------------------------------------------
target_link_libraries(${PROJECT_NAME}
        PRIVATE gtest
        PRIVATE pthread
        )
