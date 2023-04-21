#include <fmt/core.h>
// #include  "CEmulator.h"


int main(int argc, char *argv[]){
    // First argument is the name of the ROM file
    if(argc!= 2){
        fmt::print("Usage: {} <ROM file>\n", argv[0]);
        return 1;
    }

    //CEmulator emulator;

    return 0;
}
