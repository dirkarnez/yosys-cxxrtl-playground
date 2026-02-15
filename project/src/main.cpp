#include <iostream>
#include <fstream>
#include <emscripten/bind.h>
#include <backends/cxxrtl/runtime/cxxrtl/cxxrtl_vcd.h>  // oss-cad-suite\share\yosys\include\backends\cxxrtl\runtime\cxxrtl
#include "chip_cxxrtl_generated.h"

using namespace emscripten;
using namespace std;

void chip_init(void) {
    // vcd_writer is the CXXRTL object that's responsible of creating a string with
    // the VCD file contents.
    cxxrtl::vcd_writer vcd;
    vcd.timescale(1, "us");
    
    cxxrtl_design::p_chip design;
    design.step();
    // clk
    // while (1) {
    //   design.p_clk.set(false);
    //   design.step();
    //   design.p_clk.set(true);
    //   design.step();
    // }
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("chip_init", &chip_init);
}
