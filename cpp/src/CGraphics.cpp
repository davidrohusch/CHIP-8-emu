#include "CGraphics.h"
#include "chip8_consts.h"
#include <CGraphics.h>
#include <fmt/core.h>

CGraphics::CGraphics()
    : window(sf::VideoMode(width, height), "CHIP-8 cpp emu"){};

void CGraphics::DrawPixel(int x, int y, int width, int height,
                          sf::Color color) {
  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(width, height));
  rectangle.setFillColor(color);
  rectangle.setPosition(x, y);
  window.draw(rectangle);
}
void CGraphics::Render(
    const bool display[chip8::display_height][chip8::display_width],
    int pixel_width, int pixel_height) {
  /*
    Render the current frame with the given display.
    The display is simple boolean matrix where True means the given pixel is
    displayed.

    pixel_width is the width of the pixel displayed.
    pixel_height is the height of the pixel displayed.

  */

  /// TODO make drawing more dynamic to the size of the display
  /// TODO Please this is awful.
  window.clear();
  for (int y = 0; y < chip8::display_height; y++) {
    for (int x = 0; x < chip8::display_width; x++) {
      if (display[y][x]) {
        DrawPixel(x * pixel_width, y * pixel_height, pixel_width, pixel_height,
                  sf::Color::Black);
      } else {
        DrawPixel(x * pixel_width, y * pixel_height, pixel_width, pixel_height,
                  sf::Color::White);
      }
    }
  }
  window.display();
};

sf::Event CGraphics::GetEvent() { return event; }

bool CGraphics::PrepareEvent() { return window.pollEvent(event); }

void CGraphics::Close() { window.close(); }

bool CGraphics::IsRunning() const { return window.isOpen(); }