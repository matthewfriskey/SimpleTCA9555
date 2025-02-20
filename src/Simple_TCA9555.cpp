#include "SimpleTCA9555.h"

SimpleTCA9555* SimpleTCA9555::instance = nullptr;

SimpleTCA9555::SimpleTCA9555(uint8_t address) : _address(address), _inputs(0), _interruptPin(-1) {
    instance = this;
}

void SimpleTCA9555::begin(int sda, int scl, int interruptPin) {
    _interruptPin = interruptPin;

    if (sda != -1 && scl != -1) {
        Wire.begin(sda, scl);
    } else {
        Wire.begin();
    }

    Wire.beginTransmission(_address);
    Wire.write(0x06);
    Wire.write(0xFF);
    Wire.write(0xFF);
    Wire.endTransmission();

    if (_interruptPin != -1) {
        pinMode(_interruptPin, INPUT_PULLUP);
        attachInterrupt(digitalPinToInterrupt(_interruptPin), interruptHandler, FALLING);
    }

    update();
}

void SimpleTCA9555::update() {
    Wire.beginTransmission(_address);
    Wire.write(0x00);
    Wire.endTransmission();

    Wire.requestFrom(_address, (uint8_t)2);
    uint8_t port0 = Wire.read(); // P00-P07
    uint8_t port1 = Wire.read(); // P10-P17

    _inputs = (port1 << 8) | port0; // Full 16 bits: P00-P07 in 0-7, P10-P17 in 8-15
}

void SimpleTCA9555::updateFromISR() {
    Wire.beginTransmission(_address);
    Wire.write(0x00);
    Wire.endTransmission();

    Wire.requestFrom(_address, (uint8_t)2);
    uint8_t port0 = Wire.read(); // P00-P07
    uint8_t port1 = Wire.read(); // P10-P17

    _inputs = (port1 << 8) | port0; // Full 16 bits
}

void IRAM_ATTR SimpleTCA9555::interruptHandler() {
    if (instance != nullptr) {
        instance->updateFromISR();
    }
}