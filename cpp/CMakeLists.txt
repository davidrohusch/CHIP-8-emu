cmake_minimum_required(VERSION 3.00)
project(CHIP8_emu)
find_package(fmt REQUIRED)
set(CMAKE_CXX_STANDARD 20)
# Link fmt library

add_executable(CHIP8_emu src/main.cpp)
target_link_libraries(CHIP8_emu  PRIVATE fmt::fmt)
