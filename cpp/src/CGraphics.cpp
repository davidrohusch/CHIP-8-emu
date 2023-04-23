#include "CGraphics.h"
#include "chip8_consts.h"
#include <CGraphics.h>
#include <SFML/Window/Window.hpp>

CGraphics::CGraphics()
    : window(sf::VideoMode(width, height), "CHIP-8 cpp emu"){};

void CGraphics::Render(const bool display[chip8::display_height][chip8::display_width], int x_offset, int y_offset,
                       int pixel_width, int pixel_height) const {
    /*
      Render the current frame with the given display.
      The display is simple boolean matrix where True means the given pixel is
      displayed.

      x_offset is the x coordinate of the top-left corner of the display.
      y_offset is the y coordinate of the top-left corner of the display.
      pixel_width is the width of the pixel displayed.
      pixel_height is the height of the pixel displayed.

    */

};


sf::Event CGraphics::GetEvent(){
  return event;
}

bool CGraphics::PrepareEvent(){
  return window.pollEvent(event);
}

void CGraphics::Close(){
  window.close();
}