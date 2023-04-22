#include "CEmulator.h"
#include <fmt/core.h>
#include <fstream>
#include <memory>
#include <SFML/Window.hpp>

CEmulator::CEmulator(std::string_view file_path) { load_file(file_path); };

void CEmulator::run() {
  return;
  sf::Window window(sf::VideoMode(128, 64), "chip-8 emu");
  while (true) {
    
  };
};

void CEmulator::load_file(std::string_view file_path) {

  std::ifstream file(file_path.data(), std::ifstream::binary);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }
  // get length of file:
  file.seekg(0, file.end);
  size_t length = file.tellg();
  file.seekg(0, file.beg);

  m_loaded_file = std::make_shared<char *>(new char[length]);
  file.read(*m_loaded_file, length);
  file.close();
  fmt::print("Successfully loaded rom file\n");
};
