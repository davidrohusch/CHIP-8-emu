#pragma once
#include "CGraphics.h"
#include "chip8_consts.h"
#include <memory>
#include <string_view>
class CEmulator {
private:
  std::shared_ptr<char *> m_loaded_file;
  CGraphics m_graphic_wrapper;
  bool display[chip8::display_height][chip8::display_width]{};
  std::shared_ptr<char *> memory;

  void load_file(std::string_view file_path);
  void HandleEvents();
  chip8::inputs input;

public:
  CEmulator(std::string_view file_path);
  void run();
};
