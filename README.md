# SimpleTCA9555

A simple library for the TCA9555 I/O expander with interrupt-driven reading of all 16 inputs, designed for Arduino on ESP32.

## Features
- Reads all 16 inputs (P00-P07 on Port 0, P10-P17 on Port 1) from the TCA9555.
- Supports redefining inputs with `#define` (e.g., `#define reed_switch input_1`).
- Optional interrupt-driven updates using the TCA9555's INT pin.
- Compatible with PlatformIO and Arduino framework.

## Installation
1. Install via PlatformIO: `pio lib install SimpleTCA9555`
2. Or clone this repository into your `lib` folder.

## Example
```cpp
#include <SimpleTCA9555.h>

SimpleTCA9555 expander(0x20);
#define reed_switch input_1
#define window input_13

void setup() {
    expander.begin(21, 22, 23); // SDA, SCL, INT pin
}

void loop() {
    if (reed_switch) {
        // Handle input
    }
    if (window) {
        // Handle window sensor
    }
}