#pragma once
#include "chip8_consts.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class CGraphics {
private:
  const uint16_t width = chip8::display_width * chip8::multiplier;
  const uint16_t height = chip8::display_height * chip8::multiplier;
  sf::RenderWindow window;
  sf::Event event;
  void DrawPixel(int x, int y, int width, int height, sf::Color color);

public:
  CGraphics();
  ~CGraphics() = default;

  void Render(const bool display[chip8::display_height][chip8::display_width],
              int pixel_width = chip8::multiplier,
              int pixel_height = chip8::multiplier);
  void HandleWindowEvents();
  sf::Event GetEvent();
  bool PrepareEvent();
  void Close();
  bool IsRunning() const;
};