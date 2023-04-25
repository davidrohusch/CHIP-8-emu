#include "CEmulator.h"
#include "chip8_consts.h"
#include <algorithm>
#include <bitset>
#include <fmt/core.h>
#include <fstream>
#include <memory>

CEmulator::CEmulator(std::string_view file_path) {
  load_file(file_path);
  /// erase memory
  std::ranges::fill(memory, 0);
  /// Loads the font data to memory
  auto it = memory.begin();
  int offset = 0;
  for (auto &symbol : fontset) {
    std::ranges::copy(symbol.second, memory.begin() + offset*5);
    offset ++;
  }
};

void CEmulator::print_sprite(const int x, const int y,
                             const std::vector<unsigned char> &sprite) {

  int x_offset = 0;
  int y_offset = 0;
  for (auto &i : sprite) {
    auto binary = std::bitset<8>(i);
    if (y + y_offset < 0) {
      y_offset += 1;
      x_offset = 0;
      continue;
    }
    while (binary.any()) {
      if (x + x_offset < 0) {
        x_offset += 1;
        binary <<= 1;
        continue;
      }
      if ((x + x_offset) >= chip8::display_width) {
        break;
      }
      if (binary[binary.size() - 1] == true) {
        display[y + y_offset][x + x_offset] = true;
      }
      x_offset += 1;
      binary <<= 1;
    }
    y_offset += 1;
    x_offset = 0;
    if ((y + y_offset) >= chip8::display_height)
      break;
  }
};

void CEmulator::print_character(const int x, const int y,
                                const char character) {
  /*probably unsued*/
  if (character < '0' || character > 'f') {
    fmt::print("{} is not supported by the chip8 font.", character);
    return;
  }
  print_sprite(x, y,
               std::vector<unsigned char>(fontset[character].begin(),
                                          fontset[character].end()));
};

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
  case sf::Event::KeyPressed:
    if (event.key.code == sf::Keyboard::Escape) {
      m_graphic_wrapper.Close();
    }
    if (event.key.code == sf::Keyboard::F1) {
      // debug
      print_character(23, 11, 'A');
      print_character(23 + 7, 11, '5');
      print_character(23 + 14, 11, '0');
      print_character(23 + 21, 11, '4');
      break;
    }
  };
}
void CEmulator::run() {
  while (m_graphic_wrapper.IsRunning()) {
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
