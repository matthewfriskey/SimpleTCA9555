# Changelog

All notable changes to the `SimpleTCA9555` library will be documented in this file.

## [2.0.0] - 2025-02-20

### Changed
- **Breaking Change**: Replaced input methods (`input_1()` to `input_16()`) with public boolean variables (`input_1` to `input_16`). This allows variable-like syntax (e.g., `if (reed_switch)` after `#define reed_switch expander.input_1`). Users of v1.x.x must update their code from `expander.input_X()` to `expander.input_X`.

### Notes
- This major update improves readability by enabling direct variable access instead of method calls. Existing code using v1.x.x will need adjustment.

## [1.1.1] - 2025-02-20

### Changed
- Minor updates to documentation.

## [1.1.0] - 2025-02-20

### Added
- **Adjustable I2C Clock Speed**: Added a `clockSpeed` parameter to the `begin()` method, allowing users to set the I2C frequency (e.g., 100 kHz, 400 kHz). Defaults to 100 kHz for compatibility. The TCA9555 supports up to 400 kHz, while ESP32 variants can go higher.
  - Example: `expander.begin(21, 22, 23, 400000)` sets 400 kHz.

### Changed
- Updated documentation in `README.md` to reflect the new clock speed feature, including usage notes and example.
- Modified `library.json` description and keywords to mention adjustable clock speed.
- Updated the example sketch (`interrupt_example.ino`) to demonstrate the new `clockSpeed` parameter.

### Notes
- This is a minor update with no breaking changes; existing code using `begin()` without the `clockSpeed` parameter will continue to work as before, defaulting to 100 kHz.

## [1.0.0] - 2025-02-19

### Initial Release
- Initial version of the `SimpleTCA9555` library.
- Features:
  - Reading all 16 inputs (P00-P07 on Port 0, P10-P17 on Port 1) from the TCA9555.
  - Input redefinition using `#define` (e.g., `#define reed_switch input_1`).
  - Optional interrupt-driven updates via the TCA9555's INT pin.
  - Compatible with all ESP32 variants under the Arduino framework via PlatformIO.
- Default I2C clock speed fixed at 100 kHz (Arduino default).