#include "CGraphics.h"
#include <CGraphics.h>
#include <SFML/Window/Window.hpp>

CGraphics::CGraphics()
    : window(sf::VideoMode(width, height), "CHIP-8 cpp emu"){};

void CGraphics::Render(const bool **display, int x_offset, int y_offset,
                       int pixel_width, int pixel_height) const {
    /*
      Render the current frame with the given display.
      The display is simple boolean matrix where True means the given pixel is
      displayed.

      x_offset is the x coordinate of the top-left corner of the display.
      y_offset is the y coordinate of the top-left corner of the display.
      pixel_width is the width of the pixel displayed.
      pixel_height is the height of the pixel displayed.

      the display is assumed to be of size width*height of the class variables.
      If the pixel would exceed the display size it will be clipped.
    */

};