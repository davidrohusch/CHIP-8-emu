#pragma once

namespace chip8 {
constexpr int display_width = 64;
constexpr int display_height = 32;
constexpr int multiplier = 16;
constexpr int memory_size = 4096;
struct inputs {
  bool a = false;
  bool b = false;
  bool c = false;
  bool d = false;
  bool e = false;
  bool f = false;
  bool zero = false;
  bool one = false;
  bool two = false;
  bool three = false;
  bool four = false;
  bool five = false;
  bool six = false;
  bool seven = false;
  bool eight = false;
  bool nine = false;
};
} // namespace chip8
