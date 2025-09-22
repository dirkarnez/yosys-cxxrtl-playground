#include <string>
#include <iostream>
#include <emscripten/bind.h>
#include "src/chip_cxxrtl_generated.h"

using namespace emscripten;

void chip_init(void) {
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
    // constant("FNM_PATHNAME", FNM_PATHNAME);
    // constant("FNM_NOESCAPE", FNM_NOESCAPE);
    // constant("FNM_PERIOD", FNM_PERIOD);
    
    // constant("FNM_NOMATCH", FNM_NOMATCH);
    
    // constant("FNM_FILE_NAME", FNM_FILE_NAME);
    // constant("FNM_LEADING_DIR", FNM_LEADING_DIR);
    // constant("FNM_CASEFOLD", FNM_CASEFOLD);
    // constant("FNM_EXTMATCH", FNM_EXTMATCH);
}
