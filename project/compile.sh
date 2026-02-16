#!/bin/bash
# -header
yosys -p "read_verilog src/chip.v; write_cxxrtl src/chip_cxxrtl_generated.h" || exit 1
source /opt/emsdk/emsdk_env.sh
emcc -O3 -std=c++17 -I `yosys-config --datdir`/include/backends/cxxrtl/runtime -lembind -Isrc "src/main.cpp" --no-entry -sERROR_ON_UNDEFINED_SYMBOLS=0 -sINITIAL_MEMORY=128kb -sALLOW_MEMORY_GROWTH -sTOTAL_STACK=64kb -o chip.js
