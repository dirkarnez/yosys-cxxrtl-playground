[yosys-cxxrtl-playground](https://dirkarnez.github.io/yosys-cxxrtl-playground)
==============================================================================
<kbd>[**vscode-web-action**](https://github.com/dirkarnez/vscode-web-action/actions/workflows/vscode-web.yml)</kbd><br>
From [wokwi-builders/verilog-cxxrtl at main · wokwi/wokwi-builders](https://github.com/wokwi/wokwi-builders/tree/main/verilog-cxxrtl)

### Notes
- Remember `sudo chmod -R +x .` when using Docker
- Retained Emscripten-generated files (`chip.js`, `chip.wasm`) may need to manaully delete when using new Docker environment

### TODOs
- [ ] FFT
  - [VenciFreeman/FFT_ChipDesign: A 16-point radix-4 FFT chip, including Verilog codes, netlists and layout. Group project.](https://github.com/VenciFreeman/FFT_ChipDesign)
- [ ] Driver code virtual clock
  - [dirkarnez/win32-counter](https://github.com/dirkarnez/win32-counter)
  - js high resolution timer
    - [avr8js/demo/src/execute.ts at main · wokwi/avr8js](https://github.com/wokwi/avr8js/blob/main/demo/src/execute.ts)

### Tools
- [Surfer | Surfer](https://surfer-project.org/)

### Tutorials
- [CXXRTL, a Yosys Simulation Backend | Electronics etc…](https://tomverbeure.github.io/2020/08/08/CXXRTL-the-New-Yosys-Simulation-Backend.html#dumping-vcd-waveforms)
  - VCD waveforms (Using [GTKWave](https://gtkwave.sourceforge.net/))
    - [tomverbeure/cxxrtl_eval: Experiments with Yosys cxxrtl backend](https://github.com/tomverbeure/cxxrtl_eval)
      - [cxxrtl_eval/blink_vcd at master · tomverbeure/cxxrtl_eval](https://github.com/tomverbeure/cxxrtl_eval/tree/master/blink_vcd)
      - [cxxrtl_eval/blink_introspect at master · tomverbeure/cxxrtl_eval](https://github.com/tomverbeure/cxxrtl_eval/tree/master/blink_introspect)
- [write_cxxrtl - convert design to C++ RTL simulation - YosysHQ Yosys 0.47 documentation](https://yosyshq.readthedocs.io/projects/yosys/en/0.47/cmd/write_cxxrtl.html)

### Components
- [YosysHQ/nextpnr: nextpnr portable FPGA place and route tool](https://github.com/YosysHQ/nextpnr)
