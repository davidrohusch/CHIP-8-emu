cmake_minimum_required(VERSION 3.00)
project(CHIP8_emu)
add_executable(CHIP8_emu src/main.cpp)


find_package(fmt REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)
set(CMAKE_CXX_STANDARD 20)
# Link fmt library

target_link_libraries(CHIP8_emu PRIVATE fmt::fmt)
target_link_libraries(CHIP8_emu PRIVATE Boost::program_options)