cmake_minimum_required(VERSION 3.24)
project(pingiwny_rewrite C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_BUILD_TYPE Release)

add_executable(pingiwny_rewrite main.c generation.c input.c placement.c structures.h movement.c utility_functions.c)

target_compile_options(pingiwny_rewrite PRIVATE -O3 -march=native -s)
