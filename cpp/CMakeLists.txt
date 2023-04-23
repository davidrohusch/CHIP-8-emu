cmake_minimum_required(VERSION 3.00)
set(CMAKE_CXX_STANDARD 20)
project(CHIP8_emu)

set(SOURCES src/main.cpp src/CEmulator.cpp include/CEmulator.h src/CGraphics.cpp include/CEmulator.h include/chip8_consts.h)
add_executable(CHIP8_emu ${SOURCES})

target_include_directories(CHIP8_emu PRIVATE include)
target_include_directories(CHIP8_emu PRIVATE src)

find_package(fmt REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)
find_package(SFML REQUIRED COMPONENTS graphics window system)

target_link_libraries(CHIP8_emu PRIVATE fmt::fmt)
target_link_libraries(CHIP8_emu PRIVATE Boost::program_options)
target_link_libraries(CHIP8_emu PRIVATE sfml-graphics sfml-window sfml-system)