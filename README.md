# SimpleTCA9555

A simple library for the TCA9555 I/O expander with optional interrupt-driven reading of all 16 inputs and adjustable I2C clock speed, designed for Arduino on ESP32.

## Features
- Reads all 16 inputs (P00-P07 on Port 0, P10-P17 on Port 1) from the TCA9555.
- Supports redefining inputs with `#define` (e.g., `#define reed_switch input_1`).
- Optional interrupt-driven updates using the TCA9555's INT pin.
- Adjustable I2C clock speed (default 100 kHz, max 400 kHz for TCA9555).
- Compatible with PlatformIO and Arduino framework on all ESP32 variants (ESP32, S2, S3, C3, etc.).

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
    expander.begin(21, 22, 23, 400000); // SDA, SCL, INT pin, 400 kHz
}

void loop() {
    if (reed_switch) {
        // Handle input
    }
    if (window) {
        // Handle window sensor
    }
}
