#pragma once
#include "chip8_consts.h"
#include <SFML/Window.hpp>
class CGraphics {
private:
  const uint16_t width = chip8::display_width * chip8::multiplier;
  const uint16_t height = chip8::display_height * chip8::multiplier;
  sf::Window window;

public:
  CGraphics();
  ~CGraphics() = default;

  void Render(const bool **display, int x_offset = 0, int y_offset = 0,
              int pixel_width = 4, int pixel_height = 4) const;
};