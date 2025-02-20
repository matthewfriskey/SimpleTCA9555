#ifndef SIMPLETCA9555_H
#define SIMPLETCA9555_H

#include <Arduino.h>
#include <Wire.h>

/**
 * @class SimpleTCA9555
 * @brief A simple library to control the TCA9555 I/O expander in input mode with interrupt support.
 *
 * This library supports reading all 16 inputs (P00-P07 on Port 0, P10-P17 on Port 1).
 * Inputs are defined as `input_1` to `input_16` and can be redefined in your sketch
 * with custom names using `#define`. It supports optional interrupt-driven updates
 * when the TCA9555's INT pin is connected to an ESP32 GPIO pin.
 */
class SimpleTCA9555 {
public:
    SimpleTCA9555(uint8_t address);
    void begin(int sda = -1, int scl = -1, int interruptPin = -1);
    void update();

    bool input_1()  const { return _inputs & (1 << 0); }  // P00
    bool input_2()  const { return _inputs & (1 << 1); }  // P01
    bool input_3()  const { return _inputs & (1 << 2); }  // P02
    bool input_4()  const { return _inputs & (1 << 3); }  // P03
    bool input_5()  const { return _inputs & (1 << 4); }  // P04
    bool input_6()  const { return _inputs & (1 << 5); }  // P05
    bool input_7()  const { return _inputs & (1 << 6); }  // P06
    bool input_8()  const { return _inputs & (1 << 7); }  // P07
    bool input_9()  const { return _inputs & (1 << 8); }  // P10
    bool input_10() const { return _inputs & (1 << 9); }  // P11
    bool input_11() const { return _inputs & (1 << 10); } // P12
    bool input_12() const { return _inputs & (1 << 11); } // P13
    bool input_13() const { return _inputs & (1 << 12); } // P14
    bool input_14() const { return _inputs & (1 << 13); } // P15
    bool input_15() const { return _inputs & (1 << 14); } // P16
    bool input_16() const { return _inputs & (1 << 15); } // P17

private:
    uint8_t _address;
    volatile uint16_t _inputs;
    int _interruptPin;

    static void IRAM_ATTR interruptHandler();
    static SimpleTCA9555* instance;
    void updateFromISR();
};

#endif
