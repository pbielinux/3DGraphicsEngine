# Project setup ------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(3DGraphics VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)
enable_testing()

# Dependencies -------------------------------------------------------------------------------------
find_package(PkgConfig)
pkg_check_modules(GTEST "gtest" REQUIRED)
pkg_check_modules(GMOCK "gmock" REQUIRED)

# Build --------------------------------------------------------------------------------------------
if (NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Debug)
endif()

# Set compile options for G++
    add_compile_options(-Wall -Wextra)

#    add_compile_options(
#            -D_GLIBCXX_ASSERTIONS
#            -fstack-protector-strong
#            -fwrapv
#            -Wcast-align
#            -Wcast-qual
#            -Wconversion
#            -Wdouble-promotion
#            -Wfloat-equal
#            -Wformat=2
#            -Wformat-security
#            -Wmissing-include-dirs
#            -Wnon-virtual-dtor
#            -Wold-style-cast
#            -Wredundant-decls
#            -Wshadow
#            -Wsign-conversion
#            -Wswitch-enum
#            -Wuninitialized
#            -Wunused-parameter
#    )

#    # Add compile options only needed on DEBUG builds
#    add_compile_options(
#            "$<$<CONFIG:DEBUG>:-ftrapv>"
#    )
#
#    add_compile_options(
#            -Walloc-zero
#            -Walloca
#            -Wduplicated-branches
#            -Wduplicated-cond
#            -Wformat-signedness
#            -Wimplicit-fallthrough=5
#            -Wlogical-op
#            -Werror
#    )

    # For security
    # See https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html and
    # https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#Optimize-Options
    add_compile_options(-fstack-protector-all --param=ssp-buffer-size=4)


add_subdirectory(src)
add_subdirectory(test/main)

# Status -------------------------------------------------------------------------------------------
message(STATUS)
message(STATUS "${PROJECT_NAME} configuration:")
message(STATUS "  CMAKE_BUILD_TYPE         = ${CMAKE_BUILD_TYPE}")
message(STATUS)
