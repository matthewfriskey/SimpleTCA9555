# SimpleTCA9555

A simple library for the TCA9555 I/O expander with optional interrupt-driven reading of all 16 inputs and adjustable I2C clock speed, designed for Arduino on ESP32.

## Features
- Reads all 16 inputs (P00-P07 on Port 0, P10-P17 on Port 1) as public boolean variables (`input_1` to `input_16`).
- Supports renaming inputs with `#define` (e.g., `#define reed_switch expander.input_1`) for readable, variable-like syntax.
- Provides `getInputs()` to access the raw 16-bit input state for advanced handling (e.g., `switch` statements).
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

// Optional: Rename inputs for readability
#define reed_switch expander.input_1  // Bit 0
#define door_sensor expander.input_2  // Bit 1

void setup() {
    expander.begin(21, 22, 23, 400000); // SDA, SCL, INT pin, 400 kHz
}

void loop() {
  uint16_t inputState = expander.getInputs();
  for (int i = 0; i < 16; i++) {
    if (inputState & (1 << i)) {
      switch (i + 1) {
      case 1:
        Serial.println("Reed Switch Triggered");
        break;
      case 2:
        Serial.println("Door Sensor Triggered");
        break;
      default:
        Serial.println("Input " + String(i + 1) + " Triggered");
        break;
      }
    }
  }
}