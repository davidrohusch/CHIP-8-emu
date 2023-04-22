#pragma once
#include <string_view>
#include <memory>


class CEmulator {
private:
    std::shared_ptr<char*> m_loaded_file;
    bool display[64][32];
    char *memory = new char[4096];

    void load_file(std::string_view file_path);

public:
  CEmulator(std::string_view file_path);
  void run();
};
