#include "CEmulator.h"
#include <fmt/core.h>
#include <fstream>
#include <memory>

CEmulator::CEmulator(std::string_view file_path) { load_file(file_path); };
void CEmulator::HandleEvents() {
  if (!m_graphic_wrapper.PrepareEvent())
    return;
  auto event = m_graphic_wrapper.GetEvent();
  switch (event.type) {
  default:
    break;
  case sf::Event::Closed:
    m_graphic_wrapper.Close();
    break;
  }
};
void CEmulator::run() {
  while (true) {
    m_graphic_wrapper.Render(display);
    HandleEvents();
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
