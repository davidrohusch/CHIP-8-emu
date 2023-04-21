#include <boost/program_options.hpp>
#include <cstdio>
#include <fmt/core.h>
#include <iostream>

// #include  "CEmulator.h"
namespace po = boost::program_options;
int main(int argc, char *argv[]) {
  // Declare the supported options.
  po::options_description desc("Allowed options");
  desc.add_options()("help", "produce help message")("rom", po::value<std::string>(),
                                                     "loads the rom file");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help")) {
    desc.print(std::cerr);
    return 1;
  }

  if (!vm.count("rom")) {
    fmt::print("Missing rom file\n");
    return 1;
  }

  return 0;
}
